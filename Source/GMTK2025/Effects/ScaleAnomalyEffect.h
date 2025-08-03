// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Effects/AnomalyEffect.h"
#include "Components/ScaleAnomalyConfigComponent.h"
#include "ScaleAnomalyEffect.generated.h"

/**
 * Applies a random scale from the config to the target actor
 */
UCLASS(Blueprintable)
class GMTK2025_API UScaleAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	virtual void Backup_Implementation(AActor* Target) override;
	virtual void Apply_Implementation(AActor* Target) override;
	virtual void Revert_Implementation(AActor* Target) override;

private:
	/** Original actor scale so we can restore later */
	FVector OriginalScale;
};
