// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CalendarActor.generated.h"

class UWidgetComponent;
class UCalendarWidget;

UCLASS()
class GMTK2025_API ACalendarActor : public AActor
{
	GENERATED_BODY()

public:
	ACalendarActor();

	/** Call this each iteration to bump the calendar */
	UFUNCTION(BlueprintCallable, Category="Calendar")
	void AdvanceDay(int32 NewIteration, int32 TotalIterations);

protected:
	virtual void BeginPlay() override;

	/** World-space widget that displays the day */
	UPROPERTY(VisibleAnywhere, Category="Calendar")
	UWidgetComponent* CalendarWidgetComponent;

	/** Which widget blueprint to use (set in BP) */
	UPROPERTY(EditDefaultsOnly, Category="Calendar")
	TSubclassOf<UUserWidget> CalendarWidgetClass;

private:
	/** Cached pointer once spawned */
	UCalendarWidget* CalendarWidget;
};
