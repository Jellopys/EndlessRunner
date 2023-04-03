// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSection.generated.h"

UCLASS()
class MYPROJECT_API ABaseSection : public AActor
{
	GENERATED_BODY()

public:
	ABaseSection();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};
