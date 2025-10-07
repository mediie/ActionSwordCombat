// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/TraceComponent.h"
#include "Engine/DamageEvents.h"
#include "Kismet/KismetSystemLibrary.h"
#include "kismet/KismetMathLibrary.h"
#include "Interfaces/Fighter.h"

// Sets default values for this component's properties
UTraceComponent::UTraceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTraceComponent::BeginPlay()
{
	Super::BeginPlay();

	SkeletalComp = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	
}


// Called every frame
void UTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIsAttacking) { return; }
	
	FVector StartSocketLocation{ SkeletalComp->GetSocketLocation(Start) };
	FVector EndSocketLocation{ SkeletalComp->GetSocketLocation(End) };
	FQuat BladeRotation{ SkeletalComp->GetSocketQuaternion(Rotation) };

	TArray <FHitResult> OutResults;

	double WeaponDistance{
		FVector::Distance(StartSocketLocation, EndSocketLocation)
	};
	FVector BoxHalfSize{
		BoxCollisionLength,WeaponDistance, BoxCollisionLength
	};
	BoxHalfSize /= 2.0f; // BoxHalfSize = BoxHalfSize / 2

	FCollisionShape Box { FCollisionShape::MakeBox(BoxHalfSize) };

	FCollisionQueryParams IgnoreParams{ FName(TEXT("IgnoreParams")), false, GetOwner() };

	
	bool bHasFoundTargets {GetWorld()->SweepMultiByChannel(
		OutResults,
		StartSocketLocation,
		EndSocketLocation,
		BladeRotation,
		ECollisionChannel::ECC_GameTraceChannel2,
		Box,
		IgnoreParams
	) };

	
	
	if (bDebugMode)
	{
		FVector CenterPoint{
			UKismetMathLibrary::VLerp(
				StartSocketLocation, EndSocketLocation, 0.5f
			)
		};
		
		UKismetSystemLibrary::DrawDebugBox(
			GetWorld(),
			CenterPoint,
			Box.GetExtent(),
			bHasFoundTargets ? FLinearColor::Green : FLinearColor::Red,
			BladeRotation.Rotator(),
			0.1f,
			2.0f
		);
	};
	if (OutResults.Num() == 0) { return; }

	float CharacterDamage{0.0f};
	IFighter* FighterRef{Cast <IFighter>(GetOwner())};

	if (FighterRef)
	{
		CharacterDamage = FighterRef->GetDamage();
	}

	FDamageEvent TargetAttackedEvent;

	for (const FHitResult& Hit: OutResults)
	{
		AActor* TargetActor{ Hit.GetActor() };

		if (TargetsToIgnore.Contains(TargetActor)) { continue; }
		
		TargetActor->TakeDamage(
			CharacterDamage,
			TargetAttackedEvent,
			GetOwner()->GetInstigatorController(),
			GetOwner()  
		);
		TargetsToIgnore.AddUnique(TargetActor);
	}

}

void UTraceComponent::HandleResetAttack()
{
	TargetsToIgnore.Empty();
}

