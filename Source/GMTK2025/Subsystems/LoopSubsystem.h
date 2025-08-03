// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LoopSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoopTransitionStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoopContinueEvent, int32, Iteration);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoopEvent, bool, bSuccess);

UCLASS()
class GMTK2025_API ULoopSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    // Called once at game start or after a loss
    UFUNCTION(BlueprintCallable) 
    void StartLoop();
    
    // Call when player reports “I see an anomaly”
    UFUNCTION(BlueprintCallable) 
    void ReportAnomaly();
    
    // Call when player steps through the mirror to continue
    UFUNCTION(BlueprintCallable) 
    void ContinueLoop();

    // How long (seconds) the screen stays black during a transition
    UPROPERTY(EditAnywhere, Category="Loop")
    float TransitionDelay = 2.f;

    // Fires immediately so UI can start fade‐out (both advance and fail)
    UPROPERTY(BlueprintAssignable, Category="Loop")
    FOnLoopTransitionStart OnLoopTransitionStart;

    // Fires after TransitionDelay with the new iteration index
    UPROPERTY(BlueprintAssignable, Category="Loop")
    FOnLoopContinueEvent OnLoopContinue;

    // Fires immediately after a win or loss decision
    UPROPERTY(BlueprintAssignable, Category="Loop")
    FOnLoopEvent OnLoopEnd;

    // Query helpers
    UFUNCTION(BlueprintCallable, Category="Loop") int32 GetCurrentIteration() const { return CurrentIteration; }
    UFUNCTION(BlueprintCallable, Category="Loop") int32 GetTotalIterations()   const { return TotalIterations; }
    UFUNCTION(BlueprintCallable, Category="Loop") int32 GetAnomalyIteration() const { return AnomalyIteration; }

protected:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
    // The one‐shot helper that runs behind the black screen
    void PerformAdvance();
    void PerformFail();

    // Internal helpers
    void FailLoopImmediate();
    void SucceedLoopImmediate();

    // State
    int32 TotalIterations = 0;    // N
    int32 AnomalyIteration = 0;   // A (0 = no anomaly)
    int32 CurrentIteration = 0;   // 1…N

    // Timer handle for the delayed transition
    FTimerHandle TransitionTimerHandle;

    // Player original start position
    FTransform PlayerStartTransform;

public:
    UFUNCTION(BlueprintCallable, Category="Loop")
    FTransform GetPlayerStartTransform() const
    {
        return PlayerStartTransform;
    }

    UFUNCTION(BlueprintCallable, Category="Loop")
    void SetPlayerStartTransform(const FTransform& NewPlayerStartTransform)
    {
        this->PlayerStartTransform = NewPlayerStartTransform;
    }
};
