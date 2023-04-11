// Richard Hill


#include "ObjectPoolComponent.h"


UObjectPoolComponent::UObjectPoolComponent()
{
}

void UObjectPoolComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeObjects();
	
}

void UObjectPoolComponent::InitializeObjects()
{
	if (PooledObjectSubclass.Num() > 0)
	{
		UWorld* const World = GetWorld();

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
}


APooledObject* UObjectPoolComponent::SpawnPoolObject()
{
	for (APooledObject* PoolableActor : ObjectPool)
	{
		if (PoolableActor != nullptr && !PoolableActor->IsActive())
		{
			PoolableActor->TeleportTo(FVector(0,0,0), FRotator(0,0,0));
			PoolableActor->SetLifeSpan(PooledObjectLifeSpan);
			PoolableActor->SetActive(true);
			SpawnedPoolIndexes.Add(PoolableActor->GetPoolIndex());

			return PoolableActor;
		}
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
			PoolableActor->SetLifeSpan(PooledObjectLifeSpan);
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


