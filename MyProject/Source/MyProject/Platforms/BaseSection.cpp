// Richard Hill

#include "BaseSection.h"


// Sets default values
ABaseSection::ABaseSection()
{
	// PrimaryActorTick.bCanEverTick = true;
}

// void ABaseSection::Deactivate()
// {
// 	SetActiveStatus(false);
// 	// OnPooledObjectDespawn.Broadcast(this);
// }

void ABaseSection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// if (!Active)
	// 	return;
	//
	// LifeTime += DeltaTime;
	// if (LifeTime > MaxLifeTime)
	// {
	// 	SetActiveStatus(false);
	// }
}

// void ABaseSection::SetPoolIndex(int Index)
// {
// 	PoolIndex = Index;
// }
//
// void ABaseSection::SetLifeTime(int Time)
// {
// 	LifeTime = Time;
// }
//
// int ABaseSection::GetPoolIndex()
// {
// 	return PoolIndex;
// }
//
// bool ABaseSection::IsActive()
// {
// 	return Active;
// }
//
// void ABaseSection::OnActive()
// {
// 	
// }
//
// void ABaseSection::SpawnFromPool()
// {
// }
//
// void ABaseSection::ReturnToPool()
// {
// }
//
// void ABaseSection::SetActiveStatus(bool Status)
// {
// 	if (!bUsePool)
// 	{
// 		Destroy();
// 	}
// 	else
// 	{
// 		SetActorHiddenInGame(!Status);
// 		PrimaryActorTick.bCanEverTick = Status;
// 		Active = Status;
// 		LifeTime = 0.0f;
// 		
// 		if (!Status)
// 			ReturnToPool();
// 	}
// }

