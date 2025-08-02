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
	virtual void Backup_Implementation(AActor* Target) override;
	virtual void Apply_Implementation(AActor* Target) override;
	virtual void Revert_Implementation(AActor* Target) override;

private:
	/** Where we came from, so we can go back */
	FTransform OriginalTransform;
};
