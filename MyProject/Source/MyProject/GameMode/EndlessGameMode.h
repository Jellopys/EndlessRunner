// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

UCLASS()
class MYPROJECT_API AEndlessGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessGameMode();

	UFUNCTION(BlueprintCallable)
	void ResetGame();


	UFUNCTION(BlueprintCallable)
	void AddPoints();

	UFUNCTION(BlueprintCallable)
	void CreatePlatformSection();

	UFUNCTION(BlueprintCallable)
	APlayerCharacter* GetPlayerRef();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DifficultyMultiplier = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnMultiplier = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeTimeMultiplier = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentScore = 0;

	
	
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	APlayerCharacter* PlayerRef;
};
