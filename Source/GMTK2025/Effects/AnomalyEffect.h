// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnomalyEffect.generated.h"

UCLASS(Abstract, Blueprintable)
class GMTK2025_API UAnomalyEffect : public UObject
{
	GENERATED_BODY()

public:
	/** What actually happens to the Actor */
	UFUNCTION(BlueprintNativeEvent, Category="Anomaly")
	void Apply(AActor* Target);
};
