#pragma once

#include "UObject/UnrealType.h"
#include "Math/UnrealMathUtility.h"

template <typename TEnum>
TEnum GetRandomEnumValue(int32 StartIndex = 0)
{
	const UEnum* EnumPtr = StaticEnum<TEnum>();
	check(EnumPtr);

	int32 Num = EnumPtr->NumEnums();
	if (Num == 0)
	{
		return TEnum(0);
	}

	int32 ClampedStart = FMath::Clamp(StartIndex, 0, Num - 1);

	int32 RandIndex = FMath::RandRange(ClampedStart, Num - 1);

	return static_cast<TEnum>(EnumPtr->GetValueByIndex(RandIndex));
}
