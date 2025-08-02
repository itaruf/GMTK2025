// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CalendarWidget.generated.h"

class UTextBlock;

UCLASS()
class GMTK2025_API UCalendarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Bind this to a TextBlock in the Designer to show “Day X” */
	UPROPERTY(meta=(BindWidget))
	UTextBlock* DayTextBlock;

	/** Call to change the displayed day number */
	UFUNCTION(BlueprintCallable, Category="Calendar")
	void SetDay(int32 NewDay);
};
