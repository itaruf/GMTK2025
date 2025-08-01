// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TargetPoint.h"
#include "TransformAnomalyConfigComponent.generated.h"

class UStaticMeshComponent;

/**
 * Drop this on any Actor to configure world-space points for Transform anomalies
 * and visualize them as ghost meshes at each target point.
 */
UCLASS(ClassGroup=(Anomaly), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UTransformAnomalyConfigComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTransformAnomalyConfigComponent();

	/** World-space TargetPoints whose rotations/positions will be used */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transform Anomaly")
	TArray<ATargetPoint*> PossibleTargetPoints;

	/** Toggle to show or hide the in-editor preview ghost meshes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transform Anomaly")
	bool bShowPreviews = true;

#if WITH_EDITOR
	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditComponentMove(bool bFinished);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TMap<ATargetPoint*, FTransform> LastTargetPointTransforms;

#endif

protected:
	virtual void BeginPlay() override;

private:
#if WITH_EDITORONLY_DATA
	/** Currently spawned preview mesh components */
	UPROPERTY(Transient)
	TArray<UStaticMeshComponent*> PreviewMeshes;

	/** Destroy all existing preview mesh components */
	void ClearPreviews();
	/** Rebuild ghost mesh previews at each TargetPoint */
	void RebuildPreviews();
#endif
};
