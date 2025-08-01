// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Effects/AnomalyEffect.h"
#include "Enumerations/EAnomalyType.h"
#include "AnomalyComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UAnomalyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAnomalyComponent();

	/** Picks a random anomaly type according to weights */
	UFUNCTION(BlueprintCallable, Category="Anomaly")
	void Select();

	/** Applies the currently selected anomaly effect */
	UFUNCTION(BlueprintCallable, Category="Anomaly")
	void Apply();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	/** Weights for each anomaly type (defines selection probability) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Anomaly")
	TMap<EAnomalyType, int32> AnomalyTypeWeights;

	/** Mapping from anomaly type to its effect class (set in editor) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Anomaly")
	TMap<EAnomalyType, TSubclassOf<UAnomalyEffect>> EffectClassMap;

	/** The anomaly type chosen by Select() */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Anomaly")
	EAnomalyType CurrentAnomalyType;
};
