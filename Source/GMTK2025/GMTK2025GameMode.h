// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Subsystems/AnomalySubsystem.h"
#include "Subsystems/LoopSubsystem.h"
#include "GMTK2025GameMode.generated.h"

class UAnomalySubsystem;
class ULoopSubsystem;
/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AGMTK2025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	AGMTK2025GameMode();
	void BeginPlay();
	UFUNCTION(BlueprintCallable)
	void HandleLoopEnd(bool bSuccess);
};
