﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseObstacle.h"


// Sets default values
ABaseObstacle::ABaseObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABaseObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

