// AnomalyConfirmationWidget.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AnomalyConfirmationWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConfirmationResult, bool, bConfirmed);

UCLASS()
class GMTK2025_API UAnomalyConfirmationWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Broadcast true if player clicks Yes false if No */
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category="Confirm")
	FOnConfirmationResult OnConfirmationResult;

	/** Optional helper to call the delegate from Blueprint */
	UFUNCTION(BlueprintCallable, Category="Confirm")
	void ConfirmChoice(bool bConfirmed)
	{
		OnConfirmationResult.Broadcast(bConfirmed);
	}
};
