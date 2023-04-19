// Richard Hill


#include "EndlessGameMode.h"

#include "PooledObject.h"


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

	if (DifficultyMultiplier >= 3) return;
	
	DifficultyMultiplier += DeltaTime * 0.1f;
	UE_LOG(LogTemp,Warning, TEXT("DifficultyMultiplier is: %f"), DifficultyMultiplier);
}

