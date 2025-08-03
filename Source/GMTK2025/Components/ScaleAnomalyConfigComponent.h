// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScaleAnomalyConfigComponent.generated.h"

/**
 * Configure a list of scale vectors for Scale anomalies
 */
UCLASS(ClassGroup=(Anomaly), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UScaleAnomalyConfigComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UScaleAnomalyConfigComponent();

	/**
	 * List of scale factors (X, Y, Z) that can be randomly chosen for the anomaly
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scale Anomaly")
	TArray<FVector> PossibleScales;
};