// Rob Kohout All Rights Reserved


#include "Public/Components/CustomMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#pragma region ClimbTraces

TArray<FHitResult> UCustomMovementComponent::DoCapsuleTraceMultiByObject(const FVector& Start, const FVector& End, bool bShowDebugShape)
{
	TArray<FHitResult> OutCapsuleTraceHitResults;
	
	UKismetSystemLibrary::CapsuleTraceMultiForObjects(
		this,
		Start,
		End,
		ClimbCapsuleTraceRadius,
		ClimbCapsuleTraceHalfHeight,
		ClimbableSurfaceTraceTypes,
		false,
		TArray<AActor*>(),
		bShowDebugShape ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
		OutCapsuleTraceHitResults,
		false);
	
	return OutCapsuleTraceHitResults;
}

#pragma endregion