// TransformAnomalyEffect.h
#pragma once

#include "CoreMinimal.h"
#include "AnomalyEffect.h"
#include "Components/PositionAnomalyConfigComponent.h"
#include "PositionAnomalyEffect.generated.h"

UCLASS(Blueprintable)
class GMTK2025_API UPositionAnomalyEffect : public UAnomalyEffect
{
	GENERATED_BODY()

public:
	/** Runtime: grabs its UTransformAnomalyConfigComponent on the target actor */
	virtual void Apply_Implementation(AActor* Target) override;
};
