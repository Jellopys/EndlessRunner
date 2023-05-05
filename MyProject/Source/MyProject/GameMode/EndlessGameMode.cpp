// Richard Hill


#include "EndlessGameMode.h"

#include "EndlessSaveGame.h"
#include "PooledObject.h"
#include "Kismet/GameplayStatics.h"
#include "MyProject/Player/PlayerCharacter.h"
#include "Algo/Reverse.h"

AEndlessGameMode::AEndlessGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

UPlayerMovementComponent* AEndlessGameMode::GetP2MovementComp()
{
	return PlayerTwoMovementComp;
}

void AEndlessGameMode::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	LoadGame();
	
	UGameplayStatics::CreatePlayer(World, -1);
	SetPlayerRef();
}

void AEndlessGameMode::ResetGame()
{
	SaveGame();
	CurrentScore = 0;
	UGameplayStatics::OpenLevel(World, "Map_TestingGround");
}

void AEndlessGameMode::UpdateHealth()
{
	CurrentLives -= 1;

	if(CurrentLives == 0)
	{
		ResetGame();
	}
}

void AEndlessGameMode::SaveGame()
{
	if (UEndlessSaveGame* SaveGameInstance = Cast<UEndlessSaveGame>(UGameplayStatics::CreateSaveGameObject(UEndlessSaveGame::StaticClass())))
	{
		UEndlessSaveGame* LoadedGame = Cast<UEndlessSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SavedGameSlot"), 0));
		TArray<int> TempList = LoadedGame->HighScoreList;

		if (TempList.Num() < 10)
		{
			TempList.Add(CurrentScore);
		}
		else if (CurrentScore > TempList[9])
		{
			TempList.Add(CurrentScore);
			TempList.RemoveAt(9);
		}
		
		TempList.Sort();
		Algo::Reverse(TempList);
	
		SaveGameInstance->HighScoreList = TempList;
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SavedGameSlot"), 0);
	}	
}

void AEndlessGameMode::LoadGame()
{
	// Loads the saved game
	if(UEndlessSaveGame* SaveGameInstance = Cast<UEndlessSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SavedGameSlot"), 0)))
	{
		// Generate the Highscore List
		HighScoreList = SaveGameInstance->HighScoreList;
	}
}

void AEndlessGameMode::SetPlayerRef()
{
	PlayerOneRef = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(World, 0));
	PlayerTwoRef = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerPawn(World, 1));

	if (PlayerTwoRef == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get Player two"));
	}
	else
	{
		PlayerTwoMovementComp = PlayerTwoRef->GetP2MovementComponent();
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
}
