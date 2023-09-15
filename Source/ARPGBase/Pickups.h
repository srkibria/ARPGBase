// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Pickups.generated.h"

UCLASS()
class ARPGBASE_API APickups : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickups();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealthIncrease = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ManaIncrease = 0.f;
	/* Additional Functionality needed to ensure that the actor is actually a player*/
	UFUNCTION(BlueprintCallable)
	UPARAM(DisplayName = "Actionable Actor") bool OnPickedUp(AActor* OverlappedActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
