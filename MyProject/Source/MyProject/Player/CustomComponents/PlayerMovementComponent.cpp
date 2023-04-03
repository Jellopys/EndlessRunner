// Richard Hill

#include "PlayerMovementComponent.h"
#include "MyProject/Player/PlayerCharacter.h"

UPlayerMovementComponent::UPlayerMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PlayerCharacter = Cast<APlayerCharacter>(GetOwner());

}


// Called when the game starts
void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetPawnOwner();
	Capsule = Cast<UCapsuleComponent>(Owner->GetComponentByClass(UCapsuleComponent::StaticClass()));
}


// Called every frame
void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveInput = ConsumeInputVector();
	float X = MoveInput.X;
	float Y = MoveInput.Y;
	UE_LOG(LogTemp, Warning, TEXT("X is : %f  and Y is : %f"), X, Y);

	Move(MoveInput);
}

void UPlayerMovementComponent::Move(FVector Input)
{
	if (!Capsule)
		return;
	
	if (!Owner || IsValid(Owner))
		return;

	
	SafeMoveUpdatedComponent(Input, UpdatedComponent->GetComponentQuat(), true, Hit);
}

