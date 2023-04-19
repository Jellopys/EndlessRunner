// Richard Hill

#pragma once

#include "CoreMinimal.h"
// #include "Camera/CameraComponent.h"
// #include "Components/CapsuleComponent.h"
// #include "GameFramework/Pawn.h"
// #include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

class UPlayerMovementComponent;
class UCameraComponent;
class UCapsuleComponent;
class APawn;
class USpringArmComponent;

UCLASS()
class MYPROJECT_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> Capsule;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPlayerMovementComponent> MovementComponent;
	
	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;

	// Functions
	void UpdateHealth(int IncomingHealth);

	// Getters
	TObjectPtr<UCapsuleComponent> GetCapsule() const { return Capsule; }
	TObjectPtr<UCameraComponent> GetCamera() const { return Camera; }

	// Inputs
	FVector InputVector;
	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	void Space();
	
};
