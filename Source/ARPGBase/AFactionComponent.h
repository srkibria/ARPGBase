// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "AFactionComponent.generated.h"

UENUM(BlueprintType) 
enum eRelationship : uint8
{
	ENeutral		UMETA(DisplayName = "Neutral"),
	EFriendly		UMETA(DisplayName = "Friendly"),
	EHostile		UMETA(DisplayName = "Hostile"),
	eWary			UMETA(DisplayName = "Wary"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPGBASE_API UAFactionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAFactionComponent();

	UFUNCTION(BlueprintCallable)
	FGameplayTagContainer GetHostileFactions();
	
	UFUNCTION(BlueprintCallable)
	FGameplayTagContainer GetFactionsByRelationship(TEnumAsByte<eRelationship> RelationshipSearch);
	UFUNCTION(BlueprintCallable)
	bool IsActorHostile(const AActor* ActorToCheck);

	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	TMap<TEnumAsByte<eRelationship>, FGameplayTagContainer> RelationshipMap;
	
	/** Faction affilation This variable shows the faction that the character belongs to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	FGameplayTag AFaction;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
