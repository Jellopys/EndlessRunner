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

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Move(FVector Input);

	FHitResult Hit;
	APawn* Owner;
	UCapsuleComponent* Capsule;
	FVector MoveInput;

	UPROPERTY(EditAnywhere)
	APlayerCharacter* PlayerCharacter;
	
};
