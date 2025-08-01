// Fill out your copyright notice in the Description page of Project Settings.

#include "TransformAnomalyConfigComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

UTransformAnomalyConfigComponent::UTransformAnomalyConfigComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bAutoActivate = true;

#if WITH_EDITOR
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	bTickInEditor = true;
#endif
}

void UTransformAnomalyConfigComponent::BeginPlay()
{
	Super::BeginPlay();
#if WITH_EDITOR
	ClearPreviews();
#endif
}

#if WITH_EDITOR

void UTransformAnomalyConfigComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bShowPreviews)
		return;

	bool bAnyMoved = false;
	for (ATargetPoint* TP : PossibleTargetPoints)
	{
		if (!TP) continue;
		FTransform Current = TP->GetActorTransform();
		if (!LastTargetPointTransforms.Contains(TP) || !Current.Equals(LastTargetPointTransforms[TP]))
		{
			bAnyMoved = true;
			LastTargetPointTransforms.FindOrAdd(TP) = Current;
		}
	}
	if (bAnyMoved)
	{
		RebuildPreviews();
	}
}

void UTransformAnomalyConfigComponent::OnRegister()
{
	Super::OnRegister();
	RebuildPreviews();
}

void UTransformAnomalyConfigComponent::OnUnregister()
{
	ClearPreviews();
	Super::OnUnregister();
}

void UTransformAnomalyConfigComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	RebuildPreviews();
}

void UTransformAnomalyConfigComponent::PostEditComponentMove(bool bFinished)
{
	if (bFinished)
	{
		RebuildPreviews();
	}
}

void UTransformAnomalyConfigComponent::ClearPreviews()
{
	for (UStaticMeshComponent* Mesh : PreviewMeshes)
	{
		if (Mesh)
		{
			Mesh->DestroyComponent();
		}
	}
	PreviewMeshes.Empty();
}

void UTransformAnomalyConfigComponent::RebuildPreviews()
{
#if WITH_EDITOR
	if (IsRunningGame() || GIsPlayInEditorWorld) return;
#endif

	ClearPreviews();

	if (!bShowPreviews || !GetOwner())
		return;

	UStaticMeshComponent* OwnerMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	if (!OwnerMesh || !OwnerMesh->GetStaticMesh())
		return;

	UMaterialInterface* GhostMat = Cast<UMaterialInterface>(
		StaticLoadObject(UMaterialInterface::StaticClass(), nullptr,
		                 TEXT(
			                 "/Game/Anomalies/Materials/M_AnomalyWireframePreview.M_AnomalyWireframePreview")));
	

	int32 Counter = 0;
	for (ATargetPoint* TP : PossibleTargetPoints)
	{
		if (!TP)
			continue;

		FName PreviewName = MakeUniqueObjectName(this, UStaticMeshComponent::StaticClass(),
		                                         FName(*FString::Printf(
			                                         TEXT("AnomalyPreviewMesh_%p_%d"), this, Counter++)));
		UStaticMeshComponent* Mesh = NewObject<UStaticMeshComponent>(this, PreviewName);

		Mesh->SetStaticMesh(OwnerMesh->GetStaticMesh());

		FTransform PreviewTransform = OwnerMesh->GetRelativeTransform() * TP->GetActorTransform();
		Mesh->SetWorldTransform(PreviewTransform);

		Mesh->SetMobility(EComponentMobility::Movable);
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Mesh->SetVisibility(true);
		Mesh->bIsEditorOnly = true;
		if (GhostMat)
		{
			Mesh->SetMaterial(0, GhostMat);
		}
		Mesh->RegisterComponentWithWorld(GetWorld());

		PreviewMeshes.Add(Mesh);
	}
}

#endif
