// Richard Hill


#include "ObjectPoolComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessGameMode.h"
#include "PooledObject.h"


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
	for (APooledObject* PoolableActor : ObjectPool)
	{
		if (PoolableActor != nullptr && !PoolableActor->IsActive()) // for each inactive poolable actor
		{
			PoolableActor->TeleportTo(FVector(0,0,0), FRotator(0,0,0));
			// PoolableActor->SetLifeSpan(PooledObjectBaseLifeSpan);
			PoolableActor->SetLifeSpan(GameMode->LifeTimeMultiplier * GameMode->DifficultyMultiplier);
			PoolableActor->SetActive(true);
			SpawnedPoolIndexes.Add(PoolableActor->GetPoolIndex());
		
			return PoolableActor;
		}

		// Spawn new ones here?

		// Hardcoded = PooledObjectSubclass[0] , which is Sections
		APooledObject* NewSection = World->SpawnActor<APooledObject>(PooledObjectSubclass[0], FVector().ZeroVector, FRotator().ZeroRotator);

		// Hardcoded = PooledObjectSubclass[1] , which is Obstacles
		APooledObject* NewObstacle = World->SpawnActor<APooledObject>(PooledObjectSubclass[1], FVector().ZeroVector, FRotator().ZeroRotator);


		if (NewSection != nullptr)
		{
			NewSection->SetActive(false);
			NewSection->SetPoolIndex(PoolSize + PoolIndex);
			NewSection->OnPooledObjectDespawn.AddDynamic(this, &UObjectPoolComponent::OnPooledObjectDespawn);
			ObjectPool.Add(NewSection);
		}
		
		if (NewObstacle != nullptr)
		{
			NewObstacle->SetActive(false);
			NewObstacle->SetPoolIndex(PoolSize + PoolIndex);
			NewObstacle->OnPooledObjectDespawn.AddDynamic(this, &UObjectPoolComponent::OnPooledObjectDespawn);
			ObjectPool.Add(NewObstacle);
		}
		PoolIndex++;
	}

	if (SpawnedPoolIndexes.Num() > 0)
	{
		int PooledObjectIndex = SpawnedPoolIndexes[0];
		SpawnedPoolIndexes.Remove(PooledObjectIndex);
		APooledObject* PoolableActor = ObjectPool[PooledObjectIndex];

		if (PoolableActor != nullptr)
		{
			PoolableActor->SetActive(false);
			
			PoolableActor->TeleportTo(FVector(0,0,0), FRotator(0,0,0));
			PoolableActor->SetLifeSpan(GameMode->LifeTimeMultiplier * GameMode->DifficultyMultiplier);
			PoolableActor->SetActive(true);
			SpawnedPoolIndexes.Add(PoolableActor->GetPoolIndex());

			return PoolableActor;
		}
	}

	
	
	return nullptr;
}


void UObjectPoolComponent::OnPooledObjectDespawn(APooledObject* PoolActor)
{
	SpawnedPoolIndexes.Remove(PoolActor->GetPoolIndex());
}


