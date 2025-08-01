// Fill out your copyright notice in the Description page of Project Settings.

#include "TransformAnomalyEffect.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

void UTransformAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;

	// Look for the config component on this actor:
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
		   TEXT("TransformAnomalyEffect on %s: missing TransformAnomalyConfigComponent or no points !"),
		   *Target->GetName());
}
