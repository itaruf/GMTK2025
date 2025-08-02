// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LoopSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoopEvent, bool, bSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoopContinueEvent, int, Iteration);

UCLASS()
class GMTK2025_API ULoopSubsystem : public UWorldSubsystem
{
private:
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 GetTotalIterations() const
	{
		return TotalIterations;
	}

	UFUNCTION(BlueprintCallable)
	int32 GetAnomalyIteration() const
	{
		return AnomalyIteration;
	}

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentIteration() const
	{
		return CurrentIteration;
	}

	// Called once at game start or after a loss
	UFUNCTION(BlueprintCallable)
	void StartLoop();

	// Called once at game start or after a loss
	UFUNCTION(BlueprintCallable)
	void ResetLoop();

	// Call when player reports “I see an anomaly”
	UFUNCTION(BlueprintCallable)
	void ReportAnomaly();

	// Call when player steps through the mirror to continue
	UFUNCTION(BlueprintCallable)
	void ContinueLoop();

	// Loop result (true=win, false=lose)
	UPROPERTY(BlueprintAssignable)
	FOnLoopEvent OnLoopEnd;

	// Loop result (true=win, false=lose)
	UPROPERTY(BlueprintAssignable)
	FOnLoopContinueEvent OnLoopContinue;

protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	int32 TotalIterations; // N
	int32 AnomalyIteration; // A (0 = no anomaly this run)
	int32 CurrentIteration; // increments from 1…N

	void FailLoop();
	void SucceedLoop();
};
