// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TargetPoint.h"
#include "PositionAnomalyConfigComponent.generated.h"

UCLASS(ClassGroup=(Anomaly), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UPositionAnomalyConfigComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Designer-placed world-space points to teleport to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Position Anomaly")
	TArray<ATargetPoint*> TargetPoints;
};
