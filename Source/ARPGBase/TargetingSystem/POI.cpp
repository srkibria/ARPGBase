// Fill out your copyright notice in the Description page of Project Settings.


#include "POI.h"
#include "TargetingWidget.h"

UPOI::UPOI()
{
	PrimaryComponentTick.bCanEverTick = true;
	this->SetVisibleFlag(false);
}

void UPOI::BeginPlay()
{
	Super::BeginPlay();

	// Begin Play stuff here
}

void UPOI::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Tick Stuff here
}

void UPOI::ActivatePOI()
{
	bPOIIsActive = true;
	this->SetVisibleFlag(true);

	UTargetingWidget* TargetingWidget = Cast<UTargetingWidget>(this->GetUserWidgetObject());
	if (IsValid(TargetingWidget))
	{
		TargetingWidget->OnTargetAquired();
	}
	
}

void UPOI::DeactivatePOI()
{
	bPOIIsActive = false;
	this->SetVisibleFlag(true);

	UTargetingWidget* TargetingWidget = Cast<UTargetingWidget>(this->GetUserWidgetObject());
	if (IsValid(TargetingWidget))
	{
		TargetingWidget->OnTargetRemoved();
	}

}