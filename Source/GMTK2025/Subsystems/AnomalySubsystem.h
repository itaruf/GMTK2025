// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Components/AnomalyComponent.h"
#include "AnomalySubsystem.generated.h"

UCLASS()
class GMTK2025_API UAnomalySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase&) override;
	virtual void Deinitialize() override;

	void RegisterComponent(UAnomalyComponent* Comp);
	void UnregisterComponent(UAnomalyComponent* Comp);

public:
	UFUNCTION(BlueprintCallable)
	void TriggerAnomaly();

	UFUNCTION(BlueprintCallable)
	void Reset();

private:
	UPROPERTY(VisibleAnywhere)
	TSet<UAnomalyComponent*> Components;
	
	UPROPERTY(VisibleAnywhere)
	UAnomalyComponent* CurrentAnomalyEntity;

public:
	UFUNCTION(BlueprintCallable)
	UAnomalyComponent* GetCurrentAnomalyEntity() const
	{
		return CurrentAnomalyEntity;
	}
};