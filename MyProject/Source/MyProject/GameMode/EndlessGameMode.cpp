// Richard Hill


#include "EndlessGameMode.h"

#include "EndlessSaveGame.h"
#include "PooledObject.h"
#include "Kismet/GameplayStatics.h"
#include "MyProject/Player/PlayerCharacter.h"


// Sets default values
AEndlessGameMode::AEndlessGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEndlessGameMode::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEndlessGameMode::SetPlayerRef,
		1, false, 1);
}

void AEndlessGameMode::ResetGame()
{
	UE_LOG(LogTemp,Warning,TEXT("Resetting Game"));
	SaveGame();
	CurrentScore = 0;
	UGameplayStatics::OpenLevel(World, "Map_TestingGround");
}

void AEndlessGameMode::AddPoints()
{
	
}

APlayerCharacter* AEndlessGameMode::GetPlayerRef()
{
	return PlayerRef;
}

void AEndlessGameMode::SaveGame()
{
	// Creates a Save Game Object Instance
	UEndlessSaveGame* SaveGameInstance = Cast<UEndlessSaveGame>(UGameplayStatics::CreateSaveGameObject(UEndlessSaveGame::StaticClass()));

	// Add score to the saved game
	SaveGameInstance->AddHighScore(CurrentScore);
	
	// Saves the game
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SavedGameSlot"), 0);
	
}

void AEndlessGameMode::LoadGame()
{
	// // Creates a Save Game Object Instance
	// UEndlessSaveGame* SaveGameInstance = Cast<UEndlessSaveGame>(UGameplayStatics::CreateSaveGameObject(UEndlessSaveGame::StaticClass()));
	// Loads the saved game
	UEndlessSaveGame* SaveGameInstance = Cast<UEndlessSaveGame>(UGameplayStatics::LoadGameFromSlot("SavedGameSlot", 0));
	// Generate the Highscore List
	HighScoreList = SaveGameInstance->GetHighScoreList();
}

void AEndlessGameMode::SetPlayerRef()
{
	PlayerRef = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(World, 0));

	if (PlayerRef == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get Player Ref"));
	}
}

void AEndlessGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += DeltaTime;
	if (Timer >= 1)
	{
		CurrentScore += 1;
		Timer = 0;
	}
	

	if (DifficultyMultiplier >= MaxDifficulty) return;
	
	DifficultyMultiplier += DeltaTime * 0.1f;
	// UE_LOG(LogTemp,Warning, TEXT("DifficultyMultiplier is: %f"), DifficultyMultiplier);
}
