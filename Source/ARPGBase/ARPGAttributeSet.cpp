// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPGAttributeSet.h"

<<<<<<< Updated upstream
void UARPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

=======
void UARPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute,	float& NewValue) 
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetHealthMax());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetManaMax());
	}
>>>>>>> Stashed changes
}