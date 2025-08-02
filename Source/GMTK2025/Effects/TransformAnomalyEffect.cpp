// Fill out your copyright notice in the Description page of Project Settings.

#include "TransformAnomalyEffect.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

void UTransformAnomalyEffect::Backup_Implementation(AActor* Target)
{
	if (Target)
	{
		OriginalTransform = Target->GetActorTransform();
	}
}

void UTransformAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;

	if (UTransformAnomalyConfigComponent* Config =
		Target->FindComponentByClass<UTransformAnomalyConfigComponent>())
	{
		if (Config->PossibleTargetPoints.Num() > 0)
		{
			int32 Idx = FMath::RandRange(0, Config->PossibleTargetPoints.Num() - 1);
			if (ATargetPoint* Chosen = Config->PossibleTargetPoints[Idx])
			{
				Target->SetActorLocationAndRotation(
				  Chosen->GetActorLocation(),
				  Chosen->GetActorRotation()
				);
				return;
			}
		}
	}

	UE_LOG(LogTemp, Warning,
	   TEXT("TransformAnomalyEffect on %s: missing ConfigComponent or no points!"),
	   *Target->GetName());
}

void UTransformAnomalyEffect::Revert_Implementation(AActor* Target)
{
	if (Target)
	{
		Target->SetActorTransform(OriginalTransform);
	}
}
