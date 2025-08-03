// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effects/AnomalyEffect.h"
#include "Components/DecalAnomalyConfigComponent.h"
#include "Components/DecalComponent.h"
#include "DecalAnomalyEffect.generated.h"

/**
 * Applies a random decal from the config to the target actor
 */
UCLASS(Blueprintable)
class GMTK2025_API UDecalAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	virtual void Backup_Implementation(AActor* Target) override;
	virtual void Apply_Implementation(AActor* Target) override;
	virtual void Revert_Implementation(AActor* Target) override;

private:
	/** The spawned decal component so we can destroy it on revert */
	UDecalComponent* SpawnedDecal = nullptr;
};
