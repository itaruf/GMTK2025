#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JetpackComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GMTK2025_API UJetpackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UJetpackComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jetpack")
	float JetpackForce = 25000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jetpack")
	float MaxVerticalSpeed = 1200.0f;

	void ActivateJetpack();
	void DeactivateJetpack();
	void Fly();

private:
	UPROPERTY()
	ACharacter* OwnerCharacter = nullptr;
};
