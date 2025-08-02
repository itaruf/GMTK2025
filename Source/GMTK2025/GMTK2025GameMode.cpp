// Copyright Epic Games, Inc. All Rights Reserved.

#include "GMTK2025GameMode.h"


AGMTK2025GameMode::AGMTK2025GameMode()
{
}

void AGMTK2025GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (auto* Loop = GetWorld()->GetSubsystem<ULoopSubsystem>())
	{
		Loop->OnLoopEnd.AddDynamic(this, &AGMTK2025GameMode::HandleLoopEnd);
	}
}

void AGMTK2025GameMode::HandleLoopEnd(bool bSuccess)
{
	if (bSuccess)
	{
		// Show “You Win!” screen
		UE_LOG(LogTemp, Warning,
		   TEXT("You win !"));
	}
	else
	{
		// Show “You Missed It!” then reset to witness
		UE_LOG(LogTemp, Warning,
   TEXT("You missed it !"));
	}
}
