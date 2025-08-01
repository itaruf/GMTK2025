// PositionAnomalyEffect.cpp
#include "PositionAnomalyEffect.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

void UPositionAnomalyEffect::Apply_Implementation(AActor* Target)
{
	if (!Target) return;

	// Look for the config component on this actor:
	if (UPositionAnomalyConfigComponent* Config =
		Target->FindComponentByClass<UPositionAnomalyConfigComponent>())
	{
		// 1) If TargetPoints are filled, use those:
		if (Config->TargetPoints.Num() > 0)
		{
			int32 Idx = FMath::RandRange(0, Config->TargetPoints.Num() - 1);
			if (ATargetPoint* Chosen = Config->TargetPoints[Idx])
			{
				Target->SetActorLocation(Chosen->GetActorLocation());
				return;
			}
		}
	}

	UE_LOG(LogTemp, Warning,
	       TEXT("PositionAnomalyEffect on %s: missing PositionAnomalyConfigComponent or no points !"),
	       *Target->GetName());
}
