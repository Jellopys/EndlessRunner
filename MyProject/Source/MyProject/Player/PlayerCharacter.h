﻿// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.generated.h"

class UPlayerMovementComponent;
class UCameraComponent;
class UCapsuleComponent;
class APawn;
class USpringArmComponent;
class AEndlessGameMode;

UCLASS()
class MYPROJECT_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	
	UPlayerMovementComponent* GetP2MovementComponent();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	AEndlessGameMode* GameMode;
	UWorld* World;
	UPlayerMovementComponent* P2MovementComp;
	void GetP2MovComp();
	
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
	UPlayerMovementComponent* MovementComponent;
	
	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;

	// Functions
	UFUNCTION(BlueprintCallable)
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

	void MoveUp2();
	void MoveRight2();
	void MoveDown2();
	void MoveLeft2();
};
