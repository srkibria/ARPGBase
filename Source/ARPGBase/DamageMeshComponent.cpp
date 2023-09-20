// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageMeshComponent.h"
#include "ARPGStandardFunctionLibrary.h"

UDamageMeshComponent::UDamageMeshComponent()
{
	OnComponentHit.AddDynamic(this, &UDamageMeshComponent::OnHit);

	this->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
}



void UDamageMeshComponent::SetDamage(float DamageValue) 
{
	Damage = DamageValue;
}

void UDamageMeshComponent::StartSweep()
{
	this->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UDamageMeshComponent::EndSweep()
{
	this->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	DamagedActors.Empty();
}


void UDamageMeshComponent::SetManaDepletion(float DepletionValue)
{
	ManaDepletion = DepletionValue;
}

void UDamageMeshComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (DamagedActors.AddUnique(OtherActor) != -1) {
		AARPGBaseCharacter* RPGCharacter = Cast<AARPGBaseCharacter>(OtherActor);
		if (IsValid(RPGCharacter))
		{
			UAbilitySystemComponent* ASC = RPGCharacter->GetAbilitySystemComponent();
			float NewHealth = ASC->GetNumericAttribute(UARPGAttributeSet::GetHealthAttribute()) - Damage;
			ASC->SetNumericAttributeBase(UARPGAttributeSet::GetHealthAttribute(), NewHealth);
			float NewMana = ASC->GetNumericAttribute(UARPGAttributeSet::GetManaAttribute()) - ManaDepletion;
			ASC->SetNumericAttributeBase(UARPGAttributeSet::GetManaAttribute(), NewMana);

		}
	}
	
	OnHitBP(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}