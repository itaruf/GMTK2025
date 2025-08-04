// Fill out your copyright notice in the Description page of Project Settings.

#include "LoopSubsystem.h"
#include "AnomalySubsystem.h"
#include "TimerManager.h"
#include "Engine/World.h"

void ULoopSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    StartLoop();
}

void ULoopSubsystem::StartLoop()
{
    TotalIterations = 7;

    // Probability of having an anomaly (e.g., 90%)
    const float AnomalyProbability = 0.9f;

    if (FMath::FRand() < AnomalyProbability)
    {
        // Anomaly happens on some iteration
        AnomalyIteration = FMath::RandRange(1, TotalIterations);
    }
    else
    {
        // No anomaly this run
        AnomalyIteration = 0;
    }

    CurrentIteration = 0;
}

void ULoopSubsystem::ContinueLoop()
{
    CurrentIteration++;

    // 1) Did they skip an anomaly ?
    if (CurrentIteration - 1 == AnomalyIteration && AnomalyIteration != 0)
    {
        // Schedule a transition
        OnLoopTransitionStart.Broadcast();
        GetWorld()->GetTimerManager().SetTimer(
            TransitionTimerHandle, this, &ULoopSubsystem::PerformFail,
            TransitionDelay, false
        );
        return;
    }

    // 2) Did they finish all without anomaly ?
    if (CurrentIteration >= TotalIterations)
    {
        if (AnomalyIteration == 0)
        {
            // Win immediately (you could also fade first if desired)
            SucceedLoopImmediate();
        }
        else
        {
            // They never reported the anomaly
            OnLoopTransitionStart.Broadcast();
            GetWorld()->GetTimerManager().SetTimer(
                TransitionTimerHandle, this, &ULoopSubsystem::PerformFail,
                TransitionDelay, false
            );
        }
        return;
    }

    // 3) Normal advance
    OnLoopTransitionStart.Broadcast();
    GetWorld()->GetTimerManager().SetTimer(
        TransitionTimerHandle, this, &ULoopSubsystem::PerformAdvance,
        TransitionDelay, false
    );
}

void ULoopSubsystem::ReportAnomaly()
{
    if (CurrentIteration == AnomalyIteration && AnomalyIteration != 0)
    {
        SucceedLoopImmediate();
    }
    else
    {
        OnLoopTransitionStart.Broadcast();
        GetWorld()->GetTimerManager().SetTimer(
            TransitionTimerHandle, this, &ULoopSubsystem::PerformFail,
            TransitionDelay, false
        );
    }
}

void ULoopSubsystem::PerformAdvance()
{
    if (CurrentIteration == AnomalyIteration && AnomalyIteration != 0)
    {
        if (auto* Anom = GetWorld()->GetSubsystem<UAnomalySubsystem>())
        {
            Anom->TriggerAnomaly();
        }
    }

    OnLoopContinue.Broadcast(CurrentIteration);
}

void ULoopSubsystem::PerformFail()
{
    if (auto* Anom = GetWorld()->GetSubsystem<UAnomalySubsystem>())
    {
        Anom->OnAnomFail.Broadcast(Anom->GetCurrentAnomalyEntity());
        Anom->Reset();
    }

    StartLoop();

    OnLoopContinue.Broadcast(CurrentIteration);

    OnLoopEnd.Broadcast(false);
}

void ULoopSubsystem::SucceedLoopImmediate()
{
    OnLoopEnd.Broadcast(true);
}
