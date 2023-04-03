// Richard Hill


#include "BaseProjectile.h"
#include "Components/SphereComponent.h"


ABaseProjectile::ABaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	RootComponent = Sphere;
	Sphere->SetCollisionProfileName("BlockAllDynamic");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	Mesh->SetupAttachment(Sphere);
	Mesh->SetCollisionProfileName("NoCollision");
	Mesh->SetEnableGravity(false);
}

void ABaseProjectile::Deactivate()
{
	SetActiveStatus(false);
	OnPooledObjectDespawn.Broadcast(this);
}

void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	OnActive();
	Active = true;	
}

void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!Active)
	{
		return;
	}
	LifeTime += DeltaTime;
	if (LifeTime > MaxLifeTime)
	{
		SetActiveStatus(false);
	}
	else
	{
		MoveProjectile(DeltaTime);
	}
}


void ABaseProjectile::MoveProjectile(float DeltaTime)
{
	// Move Projectile
	FVector Delta = GetActorForwardVector() * TravelSpeed * DeltaTime;
	AddActorWorldOffset(Delta, false);
	
	// Sweep Hit results
	FHitResult Hit;
	FCollisionShape SphereShape = FCollisionShape::MakeSphere(Sphere->GetScaledSphereRadius());
	Sphere->SetCollisionProfileName("NoCollision");
	GetWorld()->SweepSingleByChannel(Hit, GetActorLocation(), GetActorLocation() + Delta, FQuat::Identity, ECC_WorldStatic, SphereShape);
	Sphere->SetCollisionProfileName("BlockAllDynamic");
}

void ABaseProjectile::SetActiveStatus(bool Status)
{
	OnHit();
	if (!bUsePool)
	{
		Destroy();
	}
	else
	{
		SetActorHiddenInGame(!Status);
		PrimaryActorTick.bCanEverTick = Status;
		Sphere->SetCollisionProfileName(Status ? "BlockAllDynamic" : "NoCollision");
		Sphere->SetGenerateOverlapEvents(Status);
		Active = Status;
		LifeTime = 0.0f;
		
		if (!Status)
			ReturnToPool();
	}
}

void ABaseProjectile::SetPoolIndex(int Index)
{
	PoolIndex = Index;
}

void ABaseProjectile::SetLifeTime(int Time)
{
	LifeTime = Time;
}

int ABaseProjectile::GetPoolIndex()
{
	return PoolIndex;
}

bool ABaseProjectile::IsActive()
{
	return Active;
}

void ABaseProjectile::OnActive()
{
	
}

void ABaseProjectile::ReturnToPool()
{

}

void ABaseProjectile::OnHit()
{
	
}

void ABaseProjectile::SpawnFromPool()
{
	SetActiveStatus(true);
}
