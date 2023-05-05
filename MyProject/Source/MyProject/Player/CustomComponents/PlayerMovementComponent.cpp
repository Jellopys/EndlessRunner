// Richard Hill

#include "PlayerMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyProject/Player/PlayerCharacter.h"

UPlayerMovementComponent::UPlayerMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PlayerCharacter = Cast<APlayerCharacter>(GetOwner());
	bTickBeforeOwner = true;
}

void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetPawnOwner();
	World = GetWorld();
	GameMode = Cast<AEndlessGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
	if (!Owner && !Owner->IsValidLowLevel())
	{
		UE_LOG(LogTemp,Warning,TEXT("Owner is nullptr or not valid"));
	}
	
	Capsule = Cast<UCapsuleComponent>(Owner->GetComponentByClass(UCapsuleComponent::StaticClass()));
}

void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move(DeltaTime);
}

void UPlayerMovementComponent::Move(float DeltaTime)
{
	// float X = -200, 0, 200
	// float Z = 300, 500, 700
	
	if (!Capsule || !Owner || !IsValid(Owner))
	{
		
		UE_LOG(LogTemp,Warning,TEXT("Capsule or Owner is null"));
		return;
	}	

	if (TimeElapsed < LerpDuration)
	{
		FVector CurrentLocation = Owner->GetActorLocation();
		// Lerp the Z value from the current value to the target value.
		float NewZ = FMath::Lerp(CurrentLocation.Z, ZDestination, TimeElapsed / LerpDuration);
		float NewX = FMath::Lerp(CurrentLocation.X, XDestination, TimeElapsed / LerpDuration);

		// Set the new location of the actor.
		FVector MoveVector = FVector(NewX - CurrentLocation.X, 0.f, NewZ - CurrentLocation.Z);
		SafeMoveUpdatedComponent(MoveVector, UpdatedComponent->GetComponentQuat(), true, Hit);
		TimeElapsed += DeltaTime;
	}
	
	FVector MoveVector = FVector(0, MoveSpeed * GameMode->DifficultyMultiplier * DeltaTime, 0);
	SafeMoveUpdatedComponent(MoveVector, UpdatedComponent->GetComponentQuat(), true, Hit);
}

void UPlayerMovementComponent::MoveUp()
{
	if (CurrentZLoc == 2) return;
	
	CurrentZLoc++;
	TimeElapsed = 0;
	ZDestination += 200;	
}

void UPlayerMovementComponent::MoveDown()
{
	if (CurrentZLoc == 0) return;
	
	CurrentZLoc--;
	TimeElapsed = 0;
	ZDestination -= 200;
}

void UPlayerMovementComponent::MoveRight()
{
	if (CurrentXLoc == 0) return;
	
	CurrentXLoc--;
	TimeElapsed = 0;
	XDestination -= 200;
}

void UPlayerMovementComponent::MoveLeft()
{
	if (CurrentXLoc == 2) return;
	
	CurrentXLoc++;
	TimeElapsed = 0;
	XDestination += 200;
}
