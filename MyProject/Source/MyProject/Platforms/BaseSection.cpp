// Richard Hill

#include "BaseSection.h"


// Sets default values
ABaseSection::ABaseSection()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseSection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

