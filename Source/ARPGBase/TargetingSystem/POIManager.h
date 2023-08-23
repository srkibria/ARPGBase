// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "POI.h"
#include "POIManager.generated.h"


USTRUCT(BlueprintType)
struct FPOIDescriptor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPOI* SelectedPOI = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform POIWorldTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Score = 0.f;

	// All Operators
	bool operator<(FPOIDescriptor rhs) const
	{
		return this->Score < rhs.Score;
	}

	bool operator>(FPOIDescriptor rhs) const
	{
		return this->Score > rhs.Score;
	}

	bool operator==(FPOIDescriptor rhs) const
	{
		return this->Score == rhs.Score;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPGBASE_API UPOIManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPOIManager();

	UFUNCTION(BlueprintCallable)
	TArray<UPOI*>& GetPOIs();

	UFUNCTION(BlueprintCallable)
	UPOI* GetBestPOI();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	TArray<UPOI*> CurrentPOIs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPOIDescriptor> CurrentPOIInfo;

	AActor* Owner = nullptr;
		
};
