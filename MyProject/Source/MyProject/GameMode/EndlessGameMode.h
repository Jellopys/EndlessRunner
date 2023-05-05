// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "EndlessSaveGame.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

class UPlayerMovementComponent;
class APlayerCharacter;

UCLASS()
class MYPROJECT_API AEndlessGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessGameMode();
	
	UFUNCTION(BlueprintCallable)
	void ResetGame();
	
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
	int CurrentLives = 3;

	void UpdateHealth();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> HighScoreList;

	UPlayerMovementComponent* GetP2MovementComp();
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	float Timer;
	
	void SaveGame();
	void LoadGame();
	void SetPlayerRef();
	UPROPERTY()
	APlayerCharacter* PlayerOneRef;
	UPROPERTY()
	APlayerCharacter* PlayerTwoRef;
	UPROPERTY()
	UPlayerMovementComponent* PlayerTwoMovementComp;

	FTimerHandle TimerHandle;
};
