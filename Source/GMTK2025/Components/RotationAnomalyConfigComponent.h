// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TargetPoint.h"
#include "RotationAnomalyConfigComponent.generated.h"

UCLASS(ClassGroup=(Anomaly), meta=(BlueprintSpawnableComponent))
class GMTK2025_API URotationAnomalyConfigComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Designer-placed world-space TargetPoints whose rotations will be used */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rotation Anomaly")
	TArray<ATargetPoint*> TargetPoints;
};
