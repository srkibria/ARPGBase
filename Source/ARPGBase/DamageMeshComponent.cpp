// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageMeshComponent.h"
#include "ARPGStandardFunctionLibrary.h"

UDamageMeshComponent::UDamageMeshComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &UDamageMeshComponent::OnOverlapBegin);
	SetNotifyRigidBodyCollision(true);
}



void UDamageMeshComponent::SetWATK(float NewWATKValue) 
{
	WATK = NewWATKValue;
}
void UDamageMeshComponent::SetWMATK(float NewWMATKValue)
{
	WMATK = NewWMATKValue;
}


void UDamageMeshComponent::StartSweep()
{
	HitMap.Empty();
	bInSweep = true;
	// SetNotifyRigidBodyCollision(true);
}

void UDamageMeshComponent::EndSweep()
{
	DamagedActors.Empty();
	bInSweep = false;
	// SetNotifyRigidBodyCollision(false);
}




void UDamageMeshComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AARPGBaseCharacter* OwnerCharacter = Cast<AARPGBaseCharacter>(GetOwner());
	UAbilitySystemComponent* ASC = OwnerCharacter->GetAbilitySystemComponent();
	if (bInSweep)
	{
		int32* Result = HitMap.Find(OtherActor);
		if (!Result && OtherActor != GetOwner())
		{
			HitMap.Add(OtherActor, 1);
			AARPGBaseCharacter* RPGCharacter = Cast<AARPGBaseCharacter>(OtherActor);
			if (IsValid(RPGCharacter))
			{
				float ATK = (WATK > 0.f) ? WATK + ASC->GetNumericAttribute(UARPGAttributeSet::GetStrengthAttribute()): WATK;
				float MATK = (WMATK > 0.f) ? WMATK + ASC->GetNumericAttribute(UARPGAttributeSet::GetMagicAttribute()): WMATK;
				bool bCritical = false;
				RPGCharacter->OnDamaged.Broadcast(GetOwner(), ATK, MATK, bCritical);
			}
		}
	}
}