// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "AFactionComponent.generated.h"

//Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFactionMembersChanged);

// Example of how to deal with multiple parameters. Put in Variable Type after Delegate name declaration
// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSomeDelegate, float);

//Faction Relationships
UENUM(BlueprintType) 
enum eRelationship : uint8
{
	ENeutral		UMETA(DisplayName = "Neutral"),
	EFriendly		UMETA(DisplayName = "Friendly"),
	EHostile		UMETA(DisplayName = "Hostile"),
	EWary			UMETA(DisplayName = "Wary"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class ARPGBASE_API UAFactionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAFactionComponent();

	UFUNCTION(BlueprintCallable, Category = "Faction")
	TArray<AActor*> GetKnownFactionMembers();

	UFUNCTION(BlueprintCallable, Category ="Faction")
	FGameplayTagContainer GetHostileFactions();
	
	UFUNCTION(BlueprintCallable, Category = "Faction")
	FGameplayTagContainer GetFactionsByRelationship(TEnumAsByte<eRelationship> RelationshipSearch);
	
	UFUNCTION(BlueprintCallable, Category = "Faction")
	bool IsActorHostile(const AActor* ActorToCheck);

	UFUNCTION(BlueprintCallable, Category = "Faction")
	bool IsActorInFaction(const AActor* ActorToCheck);


	/** This fuction checks tthe current list of faction members and removes anyone no longer in the faction*/
	UFUNCTION(BlueprintCallable, Category = "Faction")
	void UpdateMembers();

	void UpdateMembersClient();

	UFUNCTION(BlueprintCallable, Category = "Faction")
	FGameplayTag GetCurrentFaction();

	UFUNCTION(BlueprintCallable, Category = "Faction")
	void ChangeFaction(UAFactionComponent* FactionToChangeTo);

// Delegates
public:
	UPROPERTY(BlueprintAssignable)
	FFactionMembersChanged OnMembersChanged;
	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	TMap<TEnumAsByte<eRelationship>, FGameplayTagContainer> RelationshipMap;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	AActor* LocalFactionLeader = nullptr;

	/** This is the last list of members that were in the same faction */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	TArray<AActor*> KnownFactionMembers;

	/** Faction affilation This variable shows the faction that the character belongs to */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	FGameplayTag AFaction;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
