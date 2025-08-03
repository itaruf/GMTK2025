// Fill out your copyright notice in the Description page of Project Settings.

#include "ScaleAnomalyEffect.h"
#include "Math/UnrealMathUtility.h"

void UScaleAnomalyEffect::Backup_Implementation(AActor* Target)
{
	if (!Target) return;
	OriginalScale = Target->GetActorScale3D();
}

void UScaleAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;
	UScaleAnomalyConfigComponent* Config =
		Target->FindComponentByClass<UScaleAnomalyConfigComponent>();
	if (Config && Config->PossibleScales.Num() > 0)
	{
		int32 Idx = FMath::RandRange(0, Config->PossibleScales.Num() - 1);
		FVector ChosenScale = Config->PossibleScales[Idx];
		Target->SetActorScale3D(ChosenScale);
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("ScaleAnomalyEffect on %s: missing ConfigComponent or no scales!"),
	       *Target->GetName());
}

void UScaleAnomalyEffect::Revert_Implementation(AActor* Target)
{
	if (!Target) return;
	Target->SetActorScale3D(OriginalScale);
}
