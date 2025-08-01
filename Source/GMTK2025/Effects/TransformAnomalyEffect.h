// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnomalyEffect.h"
#include "Components/TransformAnomalyConfigComponent.h"
#include "TransformAnomalyEffect.generated.h"

UCLASS(Blueprintable)
class GMTK2025_API UTransformAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	virtual void Apply_Implementation(AActor* Target) override;
};
