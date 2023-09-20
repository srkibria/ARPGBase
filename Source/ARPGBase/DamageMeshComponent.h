// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "DamageMeshComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class ARPGBASE_API UDamageMeshComponent : public UMeshComponent
{
	GENERATED_BODY()

	UDamageMeshComponent();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Sweep")
	TArray<AActor*> DamagedActors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Sweep")
	float Damage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage Sweep")
	float ManaDepletion = 0.0f;

public:
	UFUNCTION(BlueprintCallable)
	void SetDamage(float DamageValue);
	
	UFUNCTION(BlueprintCallable)
	void SetManaDepletion(float DepletionValue);

	UFUNCTION(BlueprintCallable)
	void StartSweep();
	
	UFUNCTION(BlueprintCallable)
	void EndSweep();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION(BlueprintImplementableEvent)
	void OnHitBP(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
