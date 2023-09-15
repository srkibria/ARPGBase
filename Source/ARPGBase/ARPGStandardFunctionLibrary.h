// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayEffect.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "ARPGBaseCharacter.h"
#include "ARPGAttributeSet.h"
#include "ARPGStandardFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ARPGBASE_API UARPGStandardFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/** Modifies the health to any Actor provided it is of ARPGCharacter. */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static void HealthChange(AActor* TargetActor, float DeltaHealth);
	
	/** Modifies the Mana to any Actor provided it is of ARPGCharacter. */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static void ManaChange(AActor* HitActor, float DeltaMana);
	
};
