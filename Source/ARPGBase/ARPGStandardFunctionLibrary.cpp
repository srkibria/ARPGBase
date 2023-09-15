// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPGStandardFunctionLibrary.h"

void UARPGStandardFunctionLibrary::HealthChange(AActor* TargetActor, float DeltaHealth)
{
	//Need to add functionality to see if Actor is a player
	AARPGBaseCharacter* RPGCharacter = Cast<AARPGBaseCharacter>(TargetActor);
	if (IsValid(RPGCharacter))
	{
		UAbilitySystemComponent* ASC = RPGCharacter->GetAbilitySystemComponent();
		float NewHealth = ASC->GetNumericAttribute(UARPGAttributeSet::GetHealthAttribute()) + DeltaHealth;
		ASC->SetNumericAttributeBase(UARPGAttributeSet::GetHealthAttribute(), NewHealth);
	}
}
void UARPGStandardFunctionLibrary::ManaChange(AActor* TargetActor, float DeltaMana)
{
	//Need to add functionality to see if Actor is a player
	AARPGBaseCharacter* RPGCharacter = Cast<AARPGBaseCharacter>(TargetActor);
	if (IsValid(RPGCharacter))
	{
		UAbilitySystemComponent* ASC = RPGCharacter->GetAbilitySystemComponent();
		float NewMana = ASC->GetNumericAttribute(UARPGAttributeSet::GetManaAttribute()) + DeltaMana;
		ASC->SetNumericAttributeBase(UARPGAttributeSet::GetManaAttribute(), NewMana);
	}
}
