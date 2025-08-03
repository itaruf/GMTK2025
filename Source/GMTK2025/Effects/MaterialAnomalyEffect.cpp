// Fill out your copyright notice in the Description page of Project Settings.

#include "MaterialAnomalyEffect.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"

void UMaterialAnomalyEffect::Backup_Implementation(AActor* Target)
{
	if (!Target) return;
	// Capture original materials
	if (UStaticMeshComponent* Mesh = Target->FindComponentByClass<UStaticMeshComponent>())
	{
		OriginalMaterials.Empty();
		int32 Num = Mesh->GetNumMaterials();
		OriginalMaterials.Reserve(Num);
		for (int32 i = 0; i < Num; ++i)
		{
			OriginalMaterials.Add(Mesh->GetMaterial(i));
		}
	}
}

void UMaterialAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;

	if (UMaterialAnomalyConfigComponent* Config =
		Target->FindComponentByClass<UMaterialAnomalyConfigComponent>())
	{
		int32 Count = Config->PossibleMaterials.Num();
		if (Count > 0)
		{
			// Choose random material
			int32 Idx = FMath::RandRange(0, Count - 1);
			UMaterialInterface* Chosen = Config->PossibleMaterials[Idx];
			if (Chosen)
			{
				// Apply to all material slots
				if (UStaticMeshComponent* Mesh = Target->FindComponentByClass<UStaticMeshComponent>())
				{
					int32 Num = Mesh->GetNumMaterials();
					for (int32 i = 0; i < Num; ++i)
					{
						Mesh->SetMaterial(i, Chosen);
					}
				}
				return;
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("MaterialAnomalyEffect on %s: missing ConfigComponent or no materials!"), *Target->GetName());
}

void UMaterialAnomalyEffect::Revert_Implementation(AActor* Target)
{
	if (!Target) return;
	// Restore original materials
	if (OriginalMaterials.Num() > 0)
	{
		if (UStaticMeshComponent* Mesh = Target->FindComponentByClass<UStaticMeshComponent>())
		{
			int32 Limit = FMath::Min(OriginalMaterials.Num(), Mesh->GetNumMaterials());
			for (int32 i = 0; i < Limit; ++i)
			{
				Mesh->SetMaterial(i, OriginalMaterials[i]);
			}
		}
	}
}