// Fill out your copyright notice in the Description page of Project Settings.


#include "AFactionComponent.h"
#include "ARPGBaseCharacter.h"

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

	// We want to know when the faction leader says that their member list has changed. When that happens, we'll get the faction leaders new list and update our own list
	if (IsValid(LocalFactionLeader))
	{
		UAFactionComponent* LeaderFactionComponent = LocalFactionLeader->GetComponentByClass<UAFactionComponent>();
		if (IsValid(LeaderFactionComponent))
		{
			if (this != LeaderFactionComponent)
			{
				// Basically this calls the function UpdateMembers when the delegate OnMembersChanged broadcasts an event
				LeaderFactionComponent->OnMembersChanged.AddDynamic(this, &UAFactionComponent::UpdateMembersClient);

				/*
				//Binds to a 1 param delegate
				LocalFactionComponent->SomeDelegate.AddDynamic(this, &UAFactionComponent::SomeFunctionOneParam)
				*/
			}
		}
	}

	// ...
	
}

TArray<AActor*> UAFactionComponent::GetKnownFactionMembers() 
{
	return KnownFactionMembers;
}

// Called every frame
void UAFactionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
	// Example of broadcasting a 1 param delegate. Put the value of what you want to Broadcast within the Broadcast parenthesis
	SomeDelagate.Broadcast(DeltaTime);
	*/

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
	// Remember to check every pointer, even if it's an input
	if (IsValid(ActorToCheck))
	{
		const UAFactionComponent* FactionComponent = ActorToCheck->GetComponentByClass<UAFactionComponent>();
		if (IsValid(FactionComponent))
		{
			FGameplayTag FactionToCheck = FactionComponent->AFaction;
			return GetHostileFactions().HasTagExact(FactionToCheck);
		}
	}
	return false;
}
bool UAFactionComponent::IsActorInFaction(const AActor* ActorToCheck)
{
	// Remember to check every pointer, even if it's an input
	if (IsValid(ActorToCheck))
	{
		const UAFactionComponent* FactionComponent = ActorToCheck->GetComponentByClass<UAFactionComponent>();
		if (IsValid(FactionComponent))
		{
			FGameplayTag FactionToCheck = FactionComponent->AFaction;
			return FactionToCheck.MatchesTagExact(AFaction);
		}
	}
	return false;
}
void UAFactionComponent::UpdateMembers()
{
	TArray<AActor*> MemberCandidates;
	for (AActor* CurrentCandidate : KnownFactionMembers)
	{
		// Reminder to check pointers always	
		if (IsValid(CurrentCandidate))
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
	}
	KnownFactionMembers = MemberCandidates;
	// This broadcasts that changes have been made to the known faction member by the local faction leaader
	if (LocalFactionLeader == this->GetOwner())
	{
		OnMembersChanged.Broadcast();
	}
}

FGameplayTag UAFactionComponent::GetCurrentFaction()
{
	return AFaction;
}


void UAFactionComponent::UpdateMembersClient()
{
	// 
	if (IsValid(LocalFactionLeader))
	{
		const UAFactionComponent* LeaderFactionComponent = LocalFactionLeader->GetComponentByClass<UAFactionComponent>();
		if (IsValid(LeaderFactionComponent))
		{
			KnownFactionMembers = LeaderFactionComponent->KnownFactionMembers;
		}
	}
}

// Change the faction to the new faction
void UAFactionComponent::ChangeFaction(UAFactionComponent* FactionToChangeTo)
{
	// Changes the Faction before the Update so that it can be removed when the update is executed
	AFaction = FactionToChangeTo->AFaction;
	
	// Makes assumption that faction leaders are of the base character class.
	AARPGBaseCharacter* CurrentLeader = Cast<AARPGBaseCharacter>(LocalFactionLeader);
	AARPGBaseCharacter* NewLeader = Cast<AARPGBaseCharacter>(FactionToChangeTo->LocalFactionLeader);

	if (IsValid(CurrentLeader) && IsValid(NewLeader))
	{
		// Update the faction leader to the new leader
		LocalFactionLeader = NewLeader;
		// Add the character to the new leaders faction list
		NewLeader->Faction->KnownFactionMembers.AddUnique(this->GetOwner());
		// Updates the Delegate to broadcast appropriately
		NewLeader->Faction->OnMembersChanged.AddDynamic(this, &UAFactionComponent::UpdateMembersClient);
		CurrentLeader->Faction->OnMembersChanged.RemoveAll(this);
		// Updates members for both leaders and broadcasts changes
		CurrentLeader->Faction->UpdateMembers();
		NewLeader->Faction->UpdateMembers();
		
	}
}