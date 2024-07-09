#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthPACK.generated.h"

UCLASS()
class YOURPROJECT_API AHealthPACK : public AActor
{
	GENERATED_BODY()

public:
	AHealthPACK();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthAmount = 100.0f;
};
