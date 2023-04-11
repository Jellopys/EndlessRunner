// Richard Hill

#include "ObjectPoolManager.h"

#include "Algo/RandomShuffle.h"

AObjectPoolManager::AObjectPoolManager()
{
	SectionPoolComponent = CreateDefaultSubobject<UObjectPoolComponent>(TEXT("Section Object Pool"));
	PickupsPoolComponent = CreateDefaultSubobject<UObjectPoolComponent>(TEXT("Pickups Object Pool"));
	ObstaclesPoolComponent = CreateDefaultSubobject<UObjectPoolComponent>(TEXT("Obstacles Object Pool"));
}

void AObjectPoolManager::BeginPlay()
{
	Super::BeginPlay();
	
	CreateSpawnLocations();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AObjectPoolManager::SpawnSections, LoopTimer, true, 0.5f);

	for (int i = 0; i < 5; i++)
	{
		APooledObject* Section = SectionPoolComponent->SpawnPoolObject();
		Section->SetActorLocation(FVector(0, SectionLength * i, 0));
		SpawnIndex++;
	}
}

void AObjectPoolManager::SpawnSections()
{
	APooledObject* Section = SectionPoolComponent->SpawnPoolObject();

	// Set location of the newly spawned object.
	Section->SetActorLocation(FVector(0, SectionLength * SpawnIndex, 0));
	
	SpawnIndex++;
	
	SpawnObstacles();
	
	// PickupsPoolComponent->SpawnPoolObject();
	// ObstaclesPoolComponent->SpawnPoolObject();
}

void AObjectPoolManager::SpawnObstacles()
{
	APooledObject* Obstacle = ObstaclesPoolComponent->SpawnPoolObject();

	FVector XZ = ObstacleSpawnLocations[FMath::RandRange(0, 8)];
	FVector SpawnLoc = FVector(XZ.X, SectionLength * SpawnIndex, XZ.Z);
	
	// Set location of the newly spawned object
	Obstacle->SetActorLocation(FVector(SpawnLoc));
}

void AObjectPoolManager::CreateSpawnLocations()
{
	// Bottom row, from left
	ObstacleSpawnLocations.Add(FVector(-200,0,300));
	ObstacleSpawnLocations.Add(FVector(0,0,300));
	ObstacleSpawnLocations.Add(FVector(200,0,300));

	// Middle row, from left
	ObstacleSpawnLocations.Add(FVector(-200,0,500));
	ObstacleSpawnLocations.Add(FVector(0,0,500));
	ObstacleSpawnLocations.Add(FVector(200,0,500));

	// Top row, from left
	ObstacleSpawnLocations.Add(FVector(-200,0,700));
	ObstacleSpawnLocations.Add(FVector(0,0,700));
	ObstacleSpawnLocations.Add(FVector(200,0,700));
}




