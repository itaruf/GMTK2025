// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnomalyEffect.h"
#include "Components/RotationAnomalyConfigComponent.h"
#include "RotationAnomalyEffect.generated.h"

/**
 * Sets the actor’s rotation by picking one of the world-space target points
 * specified in a URotationAnomalyConfigComponent on the target actor.
 */
UCLASS(Blueprintable)
class GMTK2025_API URotationAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	virtual void Apply_Implementation(AActor* Target) override;
};
