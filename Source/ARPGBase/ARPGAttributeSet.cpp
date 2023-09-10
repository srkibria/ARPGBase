// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPGAttributeSet.h"

float UARPGAttributeSet::GetHealth() const
{
	return FMath::Max(Health.GetCurrentValue(), 0.0f);
}

void UARPGAttributeSet::SetHealth(float NewVal)
{
    // Do not accept values lower than zero.
    NewVal = FMath::Max(NewVal, 0.0f);

    // Make sure we have an Ability System Component instance. This should always be the case.
    UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
    if (ensure(ASC))
    {
        // Set the base value (not the current value) through the appropriate function.
        // This makes sure that any modifiers we have applied will still work properly.
        ASC->SetNumericAttributeBase(GetHealthAttribute(), NewVal);
    }
}

AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &AGASAbilityDemoCharacter::OnHealthChangedInternal);