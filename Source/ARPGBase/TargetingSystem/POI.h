// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "POI.generated.h"

/**
 * 
 */


UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ARPGBASE_API UPOI : public UWidgetComponent
{
	GENERATED_BODY()
public:

	UPOI();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, DisplayName = "Is Subtarget?")
	bool bSubtarget = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "POI Active?")
	bool bPOIIsActive = false;

	UFUNCTION(BlueprintCallable)
	void ActivatePOI();

	UFUNCTION(BlueprintCallable)
	void DeactivatePOI();

protected:
	virtual void BeginPlay() override;
private:

};
