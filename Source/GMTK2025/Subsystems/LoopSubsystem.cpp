// Fill out your copyright notice in the Description page of Project Settings.

#include "LoopSubsystem.h"
#include "AnomalySubsystem.h"
#include "Kismet/GameplayStatics.h"

void ULoopSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	StartLoop();
}

void ULoopSubsystem::StartLoop()
{
	// Choose total iterations TODO: remove hard-coded values
	TotalIterations = FMath::RandRange(5, 7);

	// 1 in (TotalIterations+1) chance to have no anomaly
	int32 Choice = FMath::RandRange(0, TotalIterations);
	AnomalyIteration = (Choice == 0 ? 0 : Choice);

	CurrentIteration = 0;
}

void ULoopSubsystem::ResetLoop()
{
	// Anomaly entity needs to revert to its initial state
	if (auto* Anom = GetWorld()->GetSubsystem<UAnomalySubsystem>())
	{
		Anom->Reset();
	}
}

void ULoopSubsystem::ContinueLoop()
{
	CurrentIteration++;

	// If they escaped past the anomaly without reporting it
	if (CurrentIteration - 1 == AnomalyIteration && AnomalyIteration != 0)
	{
		// They didn’t call ReportAnomaly(), so they missed it
		FailLoop();
		return;
	}

	// Trigger anomaly only on the chosen iteration
	if (CurrentIteration == AnomalyIteration && AnomalyIteration != 0)
	{
		if (auto* Anom = GetWorld()->GetSubsystem<UAnomalySubsystem>())
		{
			Anom->TriggerAnomaly();
		}
	}

	// If this was the last iteration
	if (CurrentIteration >= TotalIterations)
	{
		// If no anomaly was ever scheduled:
		if (AnomalyIteration == 0)
		{
			SucceedLoop();
		}
		else
		{
			// They made it to the end without reporting the scheduled anomaly
			FailLoop();
		}
	}
}

void ULoopSubsystem::ReportAnomaly()
{
	// Called when player “spots” something
	if (CurrentIteration == AnomalyIteration && AnomalyIteration != 0)
	{
		SucceedLoop();
	}
	else
	{
		FailLoop();
	}
}

void ULoopSubsystem::FailLoop()
{
	OnLoopEnd.Broadcast(false);
	// Reset the loop
	ResetLoop();
	// Restart the loop
	StartLoop();
}

void ULoopSubsystem::SucceedLoop()
{
	OnLoopEnd.Broadcast(true);
}
