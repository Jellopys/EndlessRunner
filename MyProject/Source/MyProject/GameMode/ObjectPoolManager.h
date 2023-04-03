// Richard Hill

#pragma once

#include "MyProject/Projectiles/BaseProjectile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPoolManager.generated.h"

UCLASS()
class MYPROJECT_API AObjectPoolManager : public AActor
{
	GENERATED_BODY()

public:
	AObjectPoolManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABaseSection> BaseSections;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABaseSection> BaseProjectile;

	int PoolSize = 20;

	float PooledObjectLifeSpan = 0.0f;	

protected:
	virtual void BeginPlay() override;
};
