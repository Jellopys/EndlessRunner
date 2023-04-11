// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyProject/Player/PlayerCharacter.h"
#include "PlayerMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API UPlayerMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	UPlayerMovementComponent();

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LerpSpeed = 1;


	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Move(float DeltaTime);

	FHitResult Hit;
	UPROPERTY()
	APawn* Owner;
	UPROPERTY()
	UCapsuleComponent* Capsule;
	FVector MoveInput;

	float LerpDuration = 0.3;
	float TimeElapsed = 0.3;
	double StartTime;

	UWorld* World;
	
	int CurrentXLoc = 1;
	int CurrentZLoc = 0;
	float PreviousX;
	float PreviousZ;
	float XDestination = 0;
	float ZDestination = 300;

	TArray<int> XLocations;
	TArray<int> ZLocations;

	UPROPERTY(EditAnywhere)
	APlayerCharacter* PlayerCharacter;
	
};
