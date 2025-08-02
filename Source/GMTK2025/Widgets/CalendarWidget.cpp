// Fill out your copyright notice in the Description page of Project Settings.

#include "CalendarWidget.h"
#include "Components/TextBlock.h"

void UCalendarWidget::SetDay(int32 NewDay)
{
	if (DayTextBlock)
	{
		DayTextBlock->SetText(FText::Format(
			NSLOCTEXT("Calendar", "DayFmt", "Day {0}"),
			FText::AsNumber(NewDay)
		));
	}
}
