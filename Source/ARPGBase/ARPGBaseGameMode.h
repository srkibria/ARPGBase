// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "ARPGBaseGameMode.generated.h"

UCLASS(minimalapi)
class AARPGBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** An array of all actors with a faction conmponemt*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Faction")
	TArray<AActor*> AllFactionActors;

	UFUNCTION(BlueprintCallable)
	void LoadAllFactionActors();

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetAllFactionActors();
	
	AARPGBaseGameMode();
};



