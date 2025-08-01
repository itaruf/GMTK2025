// Fill out your copyright notice in the Description page of Project Settings.

#include "AnomalySubsystem.h"

void UAnomalySubsystem::Initialize(FSubsystemCollectionBase& SubsystemCollectionBase)
{
	Super::Initialize(SubsystemCollectionBase);
}

void UAnomalySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAnomalySubsystem::RegisterComponent(UAnomalyComponent* Comp)
{
	Components.Add(Comp);
}

void UAnomalySubsystem::UnregisterComponent(UAnomalyComponent* Comp)
{
	Components.Remove(Comp);
}

void UAnomalySubsystem::TriggerAnomaly()
{
	if (Components.Num() == 0) return;

	int32 Idx = FMath::RandRange(0, Components.Num() - 1);
	UAnomalyComponent* Chosen = Components.Array()[Idx];

	Chosen->Select();
	Chosen->Apply();
}
