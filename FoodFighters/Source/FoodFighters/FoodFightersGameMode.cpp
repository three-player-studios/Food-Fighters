// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FoodFightersGameMode.h"
#include "FoodFightersCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "../Plugins/TimeManager/Source/TimeManager/Public/TimeManager.h"

AFoodFightersGameMode::AFoodFightersGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Character/FoodFighters"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
