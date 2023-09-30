// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/StaticMeshComponent.h"
#include "DamageMeshComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class ARPGBASE_API UDamageMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

	UDamageMeshComponent();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	TArray<AActor*> DamagedActors;

	UPROPERTY()
	TMap<AActor*, int32> HitMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float WATK = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float WMATK = 0.0f;

public:
	UPROPERTY(BlueprintReadOnly)
	bool bInSweep = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	FGameplayTag DamageType;
	
	UFUNCTION(BlueprintCallable)
	void SetWATK(float NewWATKValue);
	
	UFUNCTION(BlueprintCallable)
	void SetWMATK(float NewWMATKValue);

	UFUNCTION(BlueprintCallable)
	void StartSweep();
	
	UFUNCTION(BlueprintCallable)
	void EndSweep();
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
