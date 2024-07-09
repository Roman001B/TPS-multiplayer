// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBox.h"

// Sets default values
AHealthBox::AHealthBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHealthBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealthBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

