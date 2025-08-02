// Fill out your copyright notice in the Description page of Project Settings.

#include "CalendarActor.h"
#include "Components/WidgetComponent.h"
#include "Widgets/CalendarWidget.h"

ACalendarActor::ACalendarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// You can also attach a StaticMesh here if you want a mesh behind the widget
	CalendarWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("CalendarWidget"));
	RootComponent = CalendarWidgetComponent;

	// Make it world-space so it looks like a paper calendar in the scene
	CalendarWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
	CalendarWidgetComponent->SetDrawSize(FVector2D(300, 300));
	CalendarWidgetComponent->SetPivot(FVector2D(0.5f, 0.5f));
}

void ACalendarActor::BeginPlay()
{
	Super::BeginPlay();

	if (CalendarWidgetClass)
	{
		CalendarWidgetComponent->SetWidgetClass(CalendarWidgetClass);
		CalendarWidget = Cast<UCalendarWidget>(
			CalendarWidgetComponent->GetUserWidgetObject()
		);
	}
}

void ACalendarActor::AdvanceDay(int32 NewIteration, int32 /*TotalIterations*/)
{
	if (!CalendarWidget && CalendarWidgetComponent->GetUserWidgetObject())
	{
		CalendarWidget = Cast<UCalendarWidget>(
			CalendarWidgetComponent->GetUserWidgetObject()
		);
	}

	if (CalendarWidget)
	{
		CalendarWidget->SetDay(NewIteration);
		// optional: play a page-flip animation, sound, etc.
	}
}
