// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnomalyEffect.h"
#include "VisibilityAnomalyEffect.generated.h"

UCLASS(Blueprintable)
class GMTK2025_API UVisibilityAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	virtual void Backup_Implementation(AActor* Target) override;
	virtual void Apply_Implementation(AActor* Target) override;
	virtual void Revert_Implementation(AActor* Target) override;

private:
	// What the actors hidden state was before Apply
	bool bOriginalHidden = false;
};
