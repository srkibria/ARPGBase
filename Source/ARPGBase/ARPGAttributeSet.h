// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
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
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Health)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Mana)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Strength)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Defence;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Defence)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Magic;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Magic)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData MagicDefense;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, MagicDefense)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Intelligence)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Agility)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Luck)
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UARPGAttributeSet, Dexterity)


public:

};
