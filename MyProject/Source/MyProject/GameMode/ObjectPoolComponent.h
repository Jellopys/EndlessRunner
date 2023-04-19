// Richard Hill

#pragma once

// #include "PooledObject.h"
#include "ObjectPoolComponent.generated.h"

class AEndlessGameMode;
class APooledObject;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API UObjectPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UObjectPoolComponent();

	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	APooledObject* SpawnPoolObject();

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	TArray<TSubclassOf<APooledObject>> PooledObjectSubclass;
	
	UPROPERTY(EditAnywhere, Category = "Object Pool")
	int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	float PooledObjectBaseLifeSpan = 5;
	

	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PoolActor);

protected:
	virtual void BeginPlay() override;

	void InitializeObjects();

	UPROPERTY()
	TObjectPtr<AEndlessGameMode> GameMode;
	UPROPERTY()
	TObjectPtr<UWorld> World;

	TArray<TObjectPtr<APooledObject>> ObjectPool;
	TArray<int> SpawnedPoolIndexes;
	int PoolIndex = 0;
};
