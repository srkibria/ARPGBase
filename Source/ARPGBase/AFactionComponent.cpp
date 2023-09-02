// Fill out your copyright notice in the Description page of Project Settings.


#include "AFactionComponent.h"

// Sets default values for this component's properties
UAFactionComponent::UAFactionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAFactionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAFactionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FGameplayTagContainer UAFactionComponent::GetHostileFactions()
{
	return RelationshipMap.FindOrAdd(eRelationship::EHostile);
}

FGameplayTagContainer UAFactionComponent::GetFactionsByRelationship(TEnumAsByte<eRelationship> RelationshipSearch)
{
	return RelationshipMap.FindOrAdd(RelationshipSearch);
}

bool UAFactionComponent::IsActorHostile(const AActor* ActorToCheck)
{
	const UAFactionComponent* FactionComponent = ActorToCheck->GetComponentByClass<UAFactionComponent>();
	if (IsValid(FactionComponent)) 
	{
		FGameplayTag FactionToCheck = FactionComponent->AFaction;
		FGameplayTagContainer* HostileTags = RelationshipMap.Find(eRelationship::EHostile);
		if (HostileTags)
		{
			return HostileTags->HasTagExact(FactionToCheck);
		}
	}
	return false;
}

void UAFactionComponent::UpdateMembers()
{
	TArray<AActor*> MemberCandidates;
	for (AActor* CurrentCandidate : KnownFactionMembers)
	{
		UAFactionComponent* FactionComponent = CurrentCandidate->GetComponentByClass<UAFactionComponent>();
		if (IsValid(FactionComponent))
		{
			if (AFaction.MatchesTagExact(FactionComponent->GetCurrentFaction()))
			{
				MemberCandidates.Add(CurrentCandidate);
			}
		}
	}
	KnownFactionMembers = MemberCandidates;
}

FGameplayTag UAFactionComponent::GetCurrentFaction()
{
	return AFaction;
}