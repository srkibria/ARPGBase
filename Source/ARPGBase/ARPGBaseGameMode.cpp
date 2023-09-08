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

void AARPGBaseGameMode::LoadAllFactionActors() 
{
	AllFactionActors.Empty();
	TArray<AActor*> FoundActors;
	if (IsValid(GetWorld()))
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);
		

		for (AActor* ActorToCheck : FoundActors)
		{
			if (IsValid(ActorToCheck->GetComponentByClass<UAFactionComponent>()))
			{
				AllFactionActors.AddUnique(ActorToCheck);
			}
		}
	}
}

TArray<AActor*> AARPGBaseGameMode::GetAllFactionActors()
{
	return AllFactionActors;
}