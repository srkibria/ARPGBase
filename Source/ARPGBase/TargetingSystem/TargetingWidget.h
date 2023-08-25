// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TargetingWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARPGBASE_API UTargetingWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, DisplayName = "On POI Activated")
	void OnTargetAquiredBP();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, DisplayName = "On POI Deactivated")
	void OnTargetRemovedBP();

	UFUNCTION()
	void OnTargetAquired();

		UFUNCTION()
	void OnTargetRemoved();
protected:
	UPROPERTY(BlueprintReadWrite)
	UWidgetAnimation* ActivationAnimation;

	UPROPERTY(BlueprintReadWrite)
	UWidgetAnimation* DeactivationAnimation;
};
