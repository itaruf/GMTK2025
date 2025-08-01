// Fill out your copyright notice in the Description page of Project Settings.

#include "RotationAnomalyEffect.h"
#include "Components/RotationAnomalyConfigComponent.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

void URotationAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;

	// Fetch the config component from the target actor
	URotationAnomalyConfigComponent* Config =
		Target->FindComponentByClass<URotationAnomalyConfigComponent>();

	if (Config && Config->TargetPoints.Num() > 0)
	{
		// Pick a random TargetPoint and apply its world rotation
		int32 Idx = FMath::RandRange(0, Config->TargetPoints.Num() - 1);
		if (ATargetPoint* Chosen = Config->TargetPoints[Idx])
		{
			Target->SetActorRotation(Chosen->GetActorRotation());
			return;
		}
	}

	UE_LOG(LogTemp, Warning,
		   TEXT("RotationAnomalyEffect on %s: missing RotationAnomalyConfigComponent or no points !"),
		   *Target->GetName());
}
