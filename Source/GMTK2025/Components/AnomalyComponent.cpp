// Fill out your copyright notice in the Description page of Project Settings.


#include "AnomalyComponent.h"

// Sets default values for this component's properties
UAnomalyComponent::UAnomalyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AnomalyType = EAnomalyType::None;
}


// Called when the game starts
void UAnomalyComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAnomalyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

