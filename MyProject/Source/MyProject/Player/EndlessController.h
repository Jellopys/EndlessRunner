// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "EndlessController.generated.h"

class AEndlessGameMode;
class UPlayerMovementComponent;

UCLASS()
class MYPROJECT_API AEndlessController : public APlayerController
{
	GENERATED_BODY()

public:
	AEndlessController();

protected:
	virtual void BeginPlay() override;
	// virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	UPROPERTY()
	AEndlessGameMode* GameMode;
	UPROPERTY()
	UWorld* World;
	UPROPERTY()
	UPlayerMovementComponent* P2MovementComp;

	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	
	void GetP2MovComp();
	FTimerHandle TimerHandle;
};


