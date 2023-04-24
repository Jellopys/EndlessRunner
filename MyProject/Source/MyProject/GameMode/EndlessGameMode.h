// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

class APlayerCharacter;

UCLASS()
class MYPROJECT_API AEndlessGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessGameMode();

	// Functions 
	UFUNCTION(BlueprintCallable)
	void ResetGame();
	UFUNCTION(BlueprintCallable)
	void AddPoints();
	UFUNCTION(BlueprintCallable)
	APlayerCharacter* GetPlayerRef();

	
	UPROPERTY()
	UWorld* World;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DifficultyMultiplier = 1;

	/** Will stop increasing max difficulty when it reaches this */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDifficulty = 6;

	/** Higher value spawns faster intervals */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnMultiplier = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeTimeMultiplier = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> HighScoreList;

	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	float Timer;

	void SaveGame();
	void LoadGame();
	void SetPlayerRef();
	APlayerCharacter* PlayerRef;
	FTimerHandle TimerHandle;
};
