// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effects/AnomalyEffect.h"

#include "Components/MaterialAnomalyConfigComponent.h"
#include "MaterialAnomalyEffect.generated.h"

/**
 * Applies a random material from the config to the target's mesh
 */
UCLASS(Blueprintable)
class GMTK2025_API UMaterialAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	virtual void Backup_Implementation(AActor* Target) override;
	virtual void Apply_Implementation(AActor* Target) override;
	virtual void Revert_Implementation(AActor* Target) override;

private:
	/** Original materials per slot so we can restore later */
	TArray<UMaterialInterface*> OriginalMaterials;
};
