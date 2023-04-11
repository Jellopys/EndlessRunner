// Richard Hill

#pragma once

#include "MyProject/Projectiles/BaseProjectile.h"
#include "CoreMinimal.h"
#include "ObjectPoolComponent.h"
#include "GameFramework/Actor.h"
#include "ObjectPoolManager.generated.h"

UCLASS()
class MYPROJECT_API AObjectPoolManager : public AActor
{
	GENERATED_BODY()

public:
	AObjectPoolManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UObjectPoolComponent* SectionPoolComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UObjectPoolComponent* PickupsPoolComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UObjectPoolComponent* ObstaclesPoolComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APooledObject>> Sections;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APooledObject>> Pickups;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APooledObject>> Obstacles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SectionLength = 3000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoopTimer = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DifficultyMultiplier = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> ObstacleSpawnLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> PickupSpawnLocations;
	
	int PoolSize = 20;
	float PooledObjectLifeSpan = 0.0f;

	UFUNCTION(BlueprintCallable)
	void SpawnSections();
	UFUNCTION(BlueprintCallable)
	void SpawnObstacles();

	void CreateSpawnLocations();

	int SpawnIndex = 0;

	FTimerHandle TimerHandle;
	
protected:
	virtual void BeginPlay() override;
};
