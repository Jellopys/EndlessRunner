// Richard Hill


#include "ObjectPoolComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessGameMode.h"
#include "PooledObject.h"
#include "Algo/RandomShuffle.h"

UObjectPoolComponent::UObjectPoolComponent()
{
}

void UObjectPoolComponent::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld(); // will return null if the component is not actually spawned in a level
	GameMode = Cast<AEndlessGameMode>(UGameplayStatics::GetGameMode(World));
	
	InitializeObjects();
}

void UObjectPoolComponent::InitializeObjects()
{
	if (PooledObjectSubclass.Num() == 0) return;

	if (World != nullptr)
	{
		for (int i = 0; i < PooledObjectSubclass.Num(); i++)
		{
			for (int j = 0; j < PoolSize; j++)
			{
				APooledObject* PoolableActor = World->SpawnActor<APooledObject>(PooledObjectSubclass[i], FVector().ZeroVector, FRotator().ZeroRotator);

				if (PoolableActor != nullptr)
				{
					PoolableActor->SetActive(false);
					PoolableActor->SetPoolIndex(j);
					PoolableActor->OnPooledObjectDespawn.AddDynamic(this, &UObjectPoolComponent::OnPooledObjectDespawn);
					ObjectPool.Add(PoolableActor);
				}
			}
		}
	}
}


APooledObject* UObjectPoolComponent::SpawnPoolObject()
{
	int const Random = FMath::RandRange(0, ObjectPool.Num() - 1);
	APooledObject* PoolableActor = ObjectPool[Random];
	
	if (PoolableActor != nullptr && !PoolableActor->IsActive()) 
	{
		PoolableActor->TeleportTo(FVector(0,0,0), FRotator(0,0,0));
		PoolableActor->SetLifeTime(GameMode->LifeTimeMultiplier / (GameMode->DifficultyMultiplier * 0.5f));
		PoolableActor->SetActive(true);
		SpawnedPoolIndexes.Add(PoolableActor->GetPoolIndex());
		return PoolableActor;
	}
	
	if (SpawnedPoolIndexes.Num() > 0)
	{
		int const PooledObjectIndex = SpawnedPoolIndexes[0];
		SpawnedPoolIndexes.Remove(PooledObjectIndex);
		APooledObject* NewPoolableActor = ObjectPool[PooledObjectIndex];
 
		if (NewPoolableActor != nullptr)
		{	
			NewPoolableActor->SetActive(false);
			
			NewPoolableActor->TeleportTo(FVector(0,0,0), FRotator(0,0,0));
			NewPoolableActor->SetLifeTime(GameMode->LifeTimeMultiplier / (GameMode->DifficultyMultiplier * 0.5f));
			NewPoolableActor->SetActive(true);
			SpawnedPoolIndexes.Add(NewPoolableActor->GetPoolIndex());

			return NewPoolableActor;
		}
		UE_LOG(LogTemp,Warning,TEXT("Poolable Actor is null"));
	}
	
	return nullptr;
}


void UObjectPoolComponent::OnPooledObjectDespawn(APooledObject* PoolActor)
{
	SpawnedPoolIndexes.Remove(PoolActor->GetPoolIndex());
}








// // Hardcoded = PooledObjectSubclass[0] , which is Sections
// APooledObject* NewSection = World->SpawnActor<APooledObject>(PooledObjectSubclass[0], FVector().ZeroVector, FRotator().ZeroRotator);
//
// // Hardcoded = PooledObjectSubclass[1] , which is Obstacles
// APooledObject* NewObstacle = World->SpawnActor<APooledObject>(PooledObjectSubclass[1], FVector().ZeroVector, FRotator().ZeroRotator);
//
//
// if (NewSection != nullptr)
// {
// 	NewSection->SetActive(false);
// 	NewSection->SetPoolIndex(PoolSize + PoolIndex);
// 	NewSection->OnPooledObjectDespawn.AddDynamic(this, &UObjectPoolComponent::OnPooledObjectDespawn);
// 	ObjectPool.Add(NewSection);
// }
//
// if (NewObstacle != nullptr)
// {
// 	NewObstacle->SetActive(false);
// 	NewObstacle->SetPoolIndex(PoolSize + PoolIndex);
// 	NewObstacle->OnPooledObjectDespawn.AddDynamic(this, &UObjectPoolComponent::OnPooledObjectDespawn);
// 	ObjectPool.Add(NewObstacle);
// }
// PoolIndex++;


