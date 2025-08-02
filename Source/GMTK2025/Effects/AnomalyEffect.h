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
	/** Called just before Apply() to snapshot whatever state we’ll need to restore */
	UFUNCTION(BlueprintNativeEvent, Category="Anomaly")
	void Backup(AActor* Target);
	virtual void Backup_Implementation(AActor* Target) {}

	/** What actually happens to the Actor */
	UFUNCTION(BlueprintNativeEvent, Category="Anomaly")
	void Apply(AActor* Target);
	virtual void Apply_Implementation(AActor* Target) PURE_VIRTUAL(UAnomalyEffect::Apply_Implementation, );

	/** Called when we need to undo the anomaly */
	UFUNCTION(BlueprintNativeEvent, Category="Anomaly")
	void Revert(AActor* Target);
	virtual void Revert_Implementation(AActor* Target) {}
};
