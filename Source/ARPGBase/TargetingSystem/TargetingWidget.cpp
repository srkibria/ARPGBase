// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetingWidget.h"


void UTargetingWidget::OnTargetAquired()
{
	this->PlayAnimation(ActivationAnimation);
	OnTargetAquiredBP();
}

void UTargetingWidget::OnTargetRemoved()
{
	this->PlayAnimation(DeactivationAnimation);
	OnTargetRemovedBP();
}