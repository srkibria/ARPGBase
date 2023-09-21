// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "ARPGAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS(Blueprintable)
class ARPGBASE_API UARPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData HealthMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData ManaMax;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Strength;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Defense;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Magic;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData MagicDefense;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Intelligence;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Agility;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Luck;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Dexterity;


	virtual void PreAttributeChange
	(
		const FGameplayAttribute& Attribute,
		float& NewValue
	) override;

public:
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, HealthMax)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, ManaMax)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Strength)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Defense)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Magic)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, MagicDefense)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Intelligence)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Agility)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Luck)
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Dexterity)
};
