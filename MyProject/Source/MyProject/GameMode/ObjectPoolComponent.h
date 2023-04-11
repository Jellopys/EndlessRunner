// Richard Hill

#pragma once

#include "PooledObject.h"
#include "ObjectPoolComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API UObjectPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UObjectPoolComponent();

	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	APooledObject* SpawnPoolObject();

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	TArray<TSubclassOf<class APooledObject>> PooledObjectSubclass;
	
	UPROPERTY(EditAnywhere, Category = "Object Pool")
	int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	float PooledObjectLifeSpan = 0.0f;

	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PoolActor);

protected:
	virtual void BeginPlay() override;

	void InitializeObjects();

	TArray<APooledObject*> ObjectPool;
	TArray<int> SpawnedPoolIndexes;
};
