// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInterface.h"
#include "DecalAnomalyConfigComponent.generated.h"

/**
 * Configure a list of decal materials and decal size for Decal anomalies
 */
UCLASS(ClassGroup=(Anomaly), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UDecalAnomalyConfigComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDecalAnomalyConfigComponent();

	/**
	 * List of decal materials that can be randomly chosen for the anomaly
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Decal Anomaly")
	TArray<UMaterialInterface*> PossibleDecalMaterials;

	/**
	 * Size of decal (extent in local space)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Decal Anomaly")
	FVector DecalSize = FVector(256.f, 256.f, 256.f);
};