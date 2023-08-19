// Fill out your copyright notice in the Description page of Project Settings.


#include "POIManager.h"
#include "POI.h"

// Sets default values for this component's properties
UPOIManager::UPOIManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Owner = this->GetOwner();

	// ...
}

TArray<UPOI*>& UPOIManager::GetPOIs()
{
	if (CurrentPOIs.IsEmpty())
	{
		TSet<UActorComponent*> AvailableComponents = Owner->GetComponents();
		for (UActorComponent*& CurrentComponent : AvailableComponents)
		{
			UPOI* CurrentPOI = Cast<UPOI>(CurrentComponent);
			if (IsValid(CurrentPOI))
			{
				CurrentPOIs.Add(CurrentPOI);
			}
		}
	}
	return CurrentPOIs;
}

// Called when the game starts
void UPOIManager::BeginPlay()
{
	Super::BeginPlay();
	// ...
}


// Called every frame
void UPOIManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

