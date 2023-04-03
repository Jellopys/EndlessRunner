// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

class UPlayerMovementComponent;

UCLASS()
class MYPROJECT_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* Capsule;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlayerMovementComponent* MovementComponent;
	
	APlayerController* PlayerController;

	// Functions
	void UpdateHealth(int IncomingHealth);

	// Getters
	UCapsuleComponent* GetCapsule() const { return Capsule; }
	UCameraComponent* GetCamera() const { return Camera; }

	// Inputs
	void MoveForward(float Val);
	void MoveRight(float Val);
	void Space();
	
};
