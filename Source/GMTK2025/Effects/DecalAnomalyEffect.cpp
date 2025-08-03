// Fill out your copyright notice in the Description page of Project Settings.

#include "DecalAnomalyEffect.h"
#include "Math/UnrealMathUtility.h"

void UDecalAnomalyEffect::Backup_Implementation(AActor* Target)
{
	// nothing to backup ahead of decal spawn
}

void UDecalAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;
	UDecalAnomalyConfigComponent* Config =
		Target->FindComponentByClass<UDecalAnomalyConfigComponent>();
	if (!Config || Config->PossibleDecalMaterials.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("DecalAnomalyEffect on %s: missing ConfigComponent or no decal materials!"), *Target->GetName());
		return;
	}

	int32 Idx = FMath::RandRange(0, Config->PossibleDecalMaterials.Num() - 1);
	UMaterialInterface* Chosen = Config->PossibleDecalMaterials[Idx];
	if (!Chosen) return;

	// Spawn a decal component attached to actor
	SpawnedDecal = NewObject<UDecalComponent>(Target);
	SpawnedDecal->RegisterComponent();
	SpawnedDecal->AttachToComponent(Target->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	SpawnedDecal->SetDecalMaterial(Chosen);
	SpawnedDecal->DecalSize = Config->DecalSize;
}

void UDecalAnomalyEffect::Revert_Implementation(AActor* Target)
{
	if (SpawnedDecal)
	{
		SpawnedDecal->DestroyComponent();
		SpawnedDecal = nullptr;
	}
}
