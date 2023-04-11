// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PooledObject.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPooledObjectDespawn, APooledObject*, PoolActor);

UCLASS()
class MYPROJECT_API APooledObject : public AActor
{
	GENERATED_BODY()

public:
	APooledObject();

	FOnPooledObjectDespawn OnPooledObjectDespawn;

	UFUNCTION(BlueprintCallable)
	void Deactivate();

	void SetActive(bool IsActive);
	virtual void SetLifeSpan(float LifeTime) override;
	void SetPoolIndex(int Index);

	bool IsActive();
	int GetPoolIndex();

protected:

	bool Active;
	float LifeSpan = 0.0f;
	int PoolIndex;

	FTimerHandle LifeSpanTimer;	
};
