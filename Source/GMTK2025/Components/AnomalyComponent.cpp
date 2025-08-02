// Fill out your copyright notice in the Description page of Project Settings.

#include "AnomalyComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Subsystems/AnomalySubsystem.h"
#include "UObject/UObjectGlobals.h"

class UAnomalySubsystem;

UAnomalyComponent::UAnomalyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentAnomalyType = EAnomalyType::None;

	AnomalyTypeWeights.Add(EAnomalyType::Position, 1);
	AnomalyTypeWeights.Add(EAnomalyType::Rotation, 1);
	AnomalyTypeWeights.Add(EAnomalyType::Scale, 1);
}

void UAnomalyComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UAnomalySubsystem* Sub = GetWorld()->GetSubsystem<UAnomalySubsystem>())
	{
		Sub->RegisterComponent(this);
	}
}

void UAnomalyComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UAnomalySubsystem* Sub = GetWorld()->GetSubsystem<UAnomalySubsystem>())
	{
		Sub->UnregisterComponent(this);
	}

	Super::EndPlay(EndPlayReason);
}

void UAnomalyComponent::Select()
{
	// Calculate total weight
	int32 TotalWeight = 0;
	for (const auto& Pair : AnomalyTypeWeights)
	{
		TotalWeight += Pair.Value;
	}
	if (TotalWeight <= 0)
	{
		CurrentAnomalyType = EAnomalyType::None;
		return;
	}

	// Pick a random number in [1,TotalWeight]
	int32 Roll = FMath::RandRange(1, TotalWeight);
	int32 Accum = 0;
	for (const auto& Pair : AnomalyTypeWeights)
	{
		Accum += Pair.Value;
		if (Roll <= Accum)
		{
			CurrentAnomalyType = Pair.Key;
			break;
		}
	}
}

void UAnomalyComponent::Apply()
{
	if (CurrentAnomalyType == EAnomalyType::None)
	{
		return;
	}

	// Find the effect class for the chosen type
	if (TSubclassOf<UAnomalyEffect>* Found = EffectClassMap.Find(CurrentAnomalyType))
	{
		if (UClass* EffectCls = *Found)
		{
			UAnomalyEffect* Effect = NewObject<UAnomalyEffect>(this, EffectCls);
			if (Effect)
			{
				Effect->Apply(GetOwner());
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Effect class for %s is null"), *UEnum::GetValueAsString(CurrentAnomalyType));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No effect mapped for %s"), *UEnum::GetValueAsString(CurrentAnomalyType));
	}
}

void UAnomalyComponent::Reset()
{
	// Reset the entity back to its original state prior the applied effect
	
}
