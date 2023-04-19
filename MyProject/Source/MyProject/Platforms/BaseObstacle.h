// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyProject/GameMode/PooledObject.h"
#include "BaseObstacle.generated.h"

UCLASS()
class MYPROJECT_API ABaseObstacle : public APooledObject
{
	GENERATED_BODY()

public:
	ABaseObstacle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Mesh;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
