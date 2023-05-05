// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessController.h"

#include "Kismet/GameplayStatics.h"
#include "MyProject/GameMode/EndlessGameMode.h"
#include "CustomComponents/PlayerMovementComponent.h"


// Sets default values
AEndlessController::AEndlessController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndlessController::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	GameMode = Cast<AEndlessGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	// GetWorldTimerManager().SetTimer(TimerHandle, this, &AEndlessController::GetP2MovComp,
	// 	1, false, 0.2f);
}

// void AEndlessController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	check(PlayerInputComponent)
// 	
// 	PlayerInputComponent->BindAction("MoveUpP2", IE_Pressed, this, &AEndlessController::MoveUp);
// 	PlayerInputComponent->BindAction("MoveDownP2", IE_Pressed, this, &AEndlessController::MoveDown);
// 	PlayerInputComponent->BindAction("MoveRightP2", IE_Pressed, this, &AEndlessController::MoveRight);
// 	PlayerInputComponent->BindAction("MoveLeftP2", IE_Pressed, this, &AEndlessController::MoveLeft);
// }

void AEndlessController::MoveUp()
{
	P2MovementComp->MoveUp();
}

void AEndlessController::MoveDown()
{
	P2MovementComp->MoveDown();
}

void AEndlessController::MoveRight()
{
	P2MovementComp->MoveRight();
}

void AEndlessController::MoveLeft()
{
	P2MovementComp->MoveLeft();
}

void AEndlessController::GetP2MovComp()
{
	P2MovementComp = GameMode->GetP2MovementComp();
}

