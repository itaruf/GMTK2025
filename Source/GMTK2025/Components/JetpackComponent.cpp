#include "JetpackComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UJetpackComponent::UJetpackComponent()
{
	// No ticking required for event-driven logic
}

void UJetpackComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
}

void UJetpackComponent::ActivateJetpack()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("JetpackComponent: MOVE_FlYING."));
		OwnerCharacter->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
}

void UJetpackComponent::DeactivateJetpack()
{
	if (!OwnerCharacter)
		OwnerCharacter = Cast<ACharacter>(GetOwner());

	if (OwnerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("JetpackComponent: MOVE_FALLING."));
		UCharacterMovementComponent* MoveComp = OwnerCharacter->GetCharacterMovement();
		if (MoveComp)
		{
			// Set vertical velocity to zero to avoid boost
			FVector Vel = MoveComp->Velocity;
			Vel.Z = 0.0f;
			MoveComp->Velocity = Vel;
			MoveComp->SetMovementMode(MOVE_Falling);
		}
	}
}

 
void UJetpackComponent::Fly()
{
	if (!OwnerCharacter) {
		// Optional: log warning only once
		static bool bWarned = false;
		if (!bWarned) {
			UE_LOG(LogTemp, Warning, TEXT("JetpackComponent: OwnerCharacter is null in Fly()."));
			bWarned = true;
		}
		return;
	}

	UCharacterMovementComponent* MoveComp = OwnerCharacter->GetCharacterMovement();
	if (!MoveComp) {
		static bool bWarned = false;
		if (!bWarned) {
			UE_LOG(LogTemp, Warning, TEXT("JetpackComponent: CharacterMovementComponent is null in Fly()."));
			bWarned = true;
		}
		return;
	}

	FVector Vel = MoveComp->Velocity;
	float NewZ = FMath::Clamp(Vel.Z + JetpackForce * GetWorld()->GetDeltaSeconds(), 0.f, MaxVerticalSpeed);
	Vel.Z = NewZ;
	MoveComp->Velocity = Vel;
}

