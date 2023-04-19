// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPoolManager.generated.h"

class AEndlessGameMode;
class UObjectPoolComponent;
class APooledObject;

UCLASS()
class MYPROJECT_API AObjectPoolManager : public AActor
{
	GENERATED_BODY()

public:
	AObjectPoolManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UObjectPoolComponent> SectionPoolComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UObjectPoolComponent> PickupsPoolComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UObjectPoolComponent> ObstaclesPoolComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APooledObject>> Sections;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APooledObject>> Pickups;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APooledObject>> Obstacles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SectionLength = 3000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoopTimer = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DifficultyMultiplier = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> ObstacleSpawnLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> PickupSpawnLocations;
	
	int PoolSize = 20;

	UFUNCTION(BlueprintCallable)
	void SpawnSections();
	UFUNCTION(BlueprintCallable)
	void SpawnObstacles();

	void CreateSpawnLocations();


	FTimerHandle TimerHandle;
	
protected:
	virtual void BeginPlay() override;
	
	
	int SpawnIndex = 0;
	
	UPROPERTY()
	TObjectPtr<AEndlessGameMode> GameMode;
	// AEndlessGameMode* GameMode;
	UPROPERTY()
	TObjectPtr<UWorld> World;
};
