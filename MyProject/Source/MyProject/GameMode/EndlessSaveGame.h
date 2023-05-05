// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "EndlessSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UEndlessSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UEndlessSaveGame();

	UPROPERTY(EditAnywhere)
	TArray<int> HighScoreList;
	
};
