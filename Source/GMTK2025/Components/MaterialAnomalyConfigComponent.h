// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInterface.h"
#include "MaterialAnomalyConfigComponent.generated.h"

/**
 * Configure a list of materials for Material ("texture") anomalies
 */
UCLASS(ClassGroup=(Anomaly), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UMaterialAnomalyConfigComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMaterialAnomalyConfigComponent();

	/**
	 * List of materials that can be randomly chosen for the anomaly
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material Anomaly")
	TArray<UMaterialInterface*> PossibleMaterials;
};