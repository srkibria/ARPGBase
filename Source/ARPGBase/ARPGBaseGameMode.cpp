// Copyright Epic Games, Inc. All Rights Reserved.

#include "ARPGBaseGameMode.h"
#include "ARPGBaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AARPGBaseGameMode::AARPGBaseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
