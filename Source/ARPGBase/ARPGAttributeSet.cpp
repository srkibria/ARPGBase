// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPGAttributeSet.h"

void UARPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute,	float& NewValue) 
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetHealthMax());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetManaMax());
	}
	else {
		NewValue = FMath::Max(NewValue, 1.0f);
	}

}