#pragma once

#include "UObject/UnrealType.h"
#include "Math/UnrealMathUtility.h"

template<typename TEnum>
static TEnum GetRandomEnumValue()
{
	const UEnum* EnumPtr = StaticEnum<TEnum>();
	check(EnumPtr);
	
	int32 Num = EnumPtr->NumEnums();
	
	int32 RandIndex = FMath::RandRange(0, Num - 1);
	return static_cast<TEnum>(EnumPtr->GetValueByIndex(RandIndex));
}
