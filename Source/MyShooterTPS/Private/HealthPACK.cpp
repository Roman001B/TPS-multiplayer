// Fill out your copyright notice in the Description page of Project Settings.
#include "HealthPACK.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Character.h" // Подключите ваш класс персонажа

AHealthPACK::AHealthPACK()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AHealthPack::OnOverlap);
}

void AHealthPACK::BeginPlay()
{
	Super::BeginPlay();
}

void AHealthPACK::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealthPACK::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		AYourProjectCharacter* Character = Cast<AYourProjectCharacter>(OtherActor);
		if (Character)
		{
			float CurrentHealth = Character->GetHealth(); // Предположим, у вас есть метод GetHealth в классе персонажа
			if (CurrentHealth > 0 && CurrentHealth < 100)
			{
				Character->SetHealth(100); // Предположим, у вас есть метод SetHealth в классе персонажа
				Destroy();
			}
		}
	}
}

