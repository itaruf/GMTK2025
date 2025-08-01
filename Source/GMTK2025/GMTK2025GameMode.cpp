// Copyright Epic Games, Inc. All Rights Reserved.

#include "GMTK2025GameMode.h"

AGMTK2025GameMode::AGMTK2025GameMode()
{
}

void AGMTK2025GameMode::BeginPlay()
{
	Super::BeginPlay();

	if (UAnomalySubsystem* Sub = GetWorld()->GetSubsystem<UAnomalySubsystem>())
	{
		Sub->TriggerAnomaly();
	}
}
