// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyProject/GameMode/EndlessGameMode.h"
#include "PlayerMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API UPlayerMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	UPlayerMovementComponent();

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 100;
	
	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Move(float DeltaTime);

	UPROPERTY()
	APlayerCharacter* PlayerCharacter;
	UPROPERTY()
	APawn* Owner;
	UPROPERTY()
	UCapsuleComponent* Capsule;
	UPROPERTY()
	AEndlessGameMode* GameMode;
	UPROPERTY()
	UWorld* World;

	FHitResult Hit;
	
	float LerpDuration = 0.3;
	float TimeElapsed = 0.3;
	
	double Difficulty = 1;
	
	int CurrentXLoc = 1;
	int CurrentZLoc = 0;
	float XDestination = 0;
	float ZDestination = 300;
};
