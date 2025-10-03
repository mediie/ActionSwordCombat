// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Combat/LockonComponent.h"

// Sets default values for this component's properties
ULockonComponent::ULockonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULockonComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerRef = GetOwner<ACharacter>();
	Controller = GetWorld()->GetFirstPlayerController();
	MovementComp = OwnerRef->GetCharacterMovement();
	
}

void ULockonComponent::StartLockon(float Radius)
{
	FHitResult OutResult;
	FVector CurrentLocation{ GetOwner()->GetActorLocation() };
	FCollisionShape Sphere{ FCollisionShape::MakeSphere(Radius) };
	FCollisionQueryParams IgnorePrams{ 
		FName(TEXT("Ignore Query Params")),
		false,
		GetOwner()
	};
	
	bool bHasFoundTarget{ GetWorld()->SweepSingleByChannel(
		OutResult,
		CurrentLocation,
		CurrentLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		Sphere,
		IgnorePrams
	) };


	if (!bHasFoundTarget) { return; }
	else
	{ UE_LOG(LogTemp, Warning, TEXT("Found Target: %s"), *OutResult.GetActor()->GetName());

		Controller->SetIgnoreLookInput(true);
		MovementComp->bOrientRotationToMovement = false;
		MovementComp->bOrientRotationToMovement = true;
		FRotator LookAtRotation{ (OutResult.GetActor()->GetActorLocation() - CurrentLocation).Rotation() };
		LookAtRotation.Pitch = 0.0f;
		LookAtRotation.Roll = 0.0f;
		OwnerRef->SetActorRotation(LookAtRotation);
	}
}


// Called every frame
void ULockonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

