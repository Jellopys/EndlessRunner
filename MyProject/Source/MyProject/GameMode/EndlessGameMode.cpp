// Richard Hill


#include "EndlessGameMode.h"


// Sets default values
AEndlessGameMode::AEndlessGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndlessGameMode::ResetGame()
{
}

void AEndlessGameMode::AddPoints()
{
}

void AEndlessGameMode::CreatePlatformSection()
{
}

APlayerCharacter* AEndlessGameMode::GetPlayerRef()
{
	return PlayerRef;
}

void AEndlessGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEndlessGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

