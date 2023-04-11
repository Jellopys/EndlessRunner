// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "MyProject/GameMode/PooledObject.h"
#include "BaseSection.generated.h"

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPooledObjectDespawn, ABaseSection*, PoolActor);

UCLASS()
class MYPROJECT_API ABaseSection : public APooledObject
{
	GENERATED_BODY()

public:
	ABaseSection();
	// UFUNCTION(BlueprintCallable)
	// void Deactivate();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Delegate
	// FOnPooledObjectDespawn OnPooledObjectDespawn;
	
	// Variables
	float TravelSpeed = 100.f;
	UPROPERTY(BlueprintReadWrite)
	float MaxLifeTime = 5.0f;
	UPROPERTY(BlueprintReadWrite)
	bool bUsePool = true;

	// Functions
	// void SetPoolIndex(int Index);
	// void SetLifeTime(int Time);
	// int GetPoolIndex();
	// bool IsActive();
	// void OnActive();
	// void SpawnFromPool();
	// void ReturnToPool();
	// void SetActiveStatus(bool Status);
	
	float LifeTime = 0;
	bool Active = true;
	int PoolIndex;
};
