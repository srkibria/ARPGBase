// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "ARPGAttributeSet.generated.h"

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
	FGameplayAttributeData Mana;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RPG Stats")
	FGameplayAttributeData Defence;
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


public:
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Health);
	float GetHealth() const;
	void SetHealth(float NewVal);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);

	//~ Helper functions for "Health" attributes

	/* This set of helper functions cannot be implemented without an ability systemm component. Come back later

	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Health);
	float GetHealth() const;
	void SetHealth(float NewVal);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);
	//~ Helper Funtions for "Mana" attributes
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Mana);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Mana);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Mana);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Mana);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Strength);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Strength);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Strength);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Strength);

	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Defence);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Defence);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Defence);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Defence);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Magic);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Magic);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Magic);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Magic);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, MagicDefense);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MagicDefense);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MagicDefense);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(MagicDefense);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Intelligence);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Intelligence);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Intelligence);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Intelligence);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Agility);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Agility);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Agility);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Agility);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Luck);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Luck);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Luck);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Luck);

	//
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UARPGAttributeSet, Dexterity);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Dexterity);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Dexterity);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Dexterity);

	*/

};
