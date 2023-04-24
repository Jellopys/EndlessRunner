// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "MyProject/GameMode/PooledObject.h"
#include "BaseProjectile.generated.h"

// DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPooledObjectDespawn, ABaseProjectile*, PoolActor);

UCLASS()
class MYPROJECT_API ABaseProjectile : public APooledObject
{
	GENERATED_BODY()

public:
	ABaseProjectile();

	// UFUNCTION(BlueprintCallable)
	// void Deactivate();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Delegate
	// FOnPooledObjectDespawn OnPooledObjectDespawn;

	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* Sphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
	
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
	// void OnHit();
	void MoveProjectile(float DeltaTime);
	void SetActiveStatus(bool Status);

	
	TArray<AActor*> IgnoreList;
	AActor* Parent;
	float LifeTime = 0;
	bool Active = true;
	int PoolIndex;
};
