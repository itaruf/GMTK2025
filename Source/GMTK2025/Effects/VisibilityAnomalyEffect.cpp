// Fill out your copyright notice in the Description page of Project Settings.

#include "VisibilityAnomalyEffect.h"
#include "GameFramework/Actor.h"

void UVisibilityAnomalyEffect::Backup_Implementation(AActor* Target)
{
	if (Target)
	{
		bOriginalHidden = Target->IsHidden();
	}
}

void UVisibilityAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (Target)
	{
		Target->SetActorHiddenInGame(true);
		Target->SetActorEnableCollision(false);
	}
}

void UVisibilityAnomalyEffect::Revert_Implementation(AActor* Target)
{
	if (Target)
	{
		Target->SetActorHiddenInGame(bOriginalHidden);
		if (!bOriginalHidden)
		{
			Target->SetActorEnableCollision(true);
		}
	}
}
