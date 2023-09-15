// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups.h"
#include "ARPGBaseCharacter.h"
#include "ARPGAttributeSet.h"

// Sets default values
APickups::APickups()
{
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APickups::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickups::OnPickedUp(AActor* OverlappedActor)
{
	//Need to add functionality to see if Actor is a player
	AARPGBaseCharacter* RPGCharacter = Cast<AARPGBaseCharacter>(OverlappedActor);
	if (IsValid(RPGCharacter))
	{
		UAbilitySystemComponent* ASC = RPGCharacter->GetAbilitySystemComponent();
		float NewHealth = ASC->GetNumericAttribute(UARPGAttributeSet::GetHealthAttribute()) + HealthIncrease;
		ASC->SetNumericAttributeBase(UARPGAttributeSet::GetHealthAttribute(), NewHealth);
		float NewMana = ASC->GetNumericAttribute(UARPGAttributeSet::GetManaAttribute()) + ManaIncrease;
		ASC->SetNumericAttributeBase(UARPGAttributeSet::GetManaAttribute(), NewHealth);
		return true;
	}
	return false;
}

