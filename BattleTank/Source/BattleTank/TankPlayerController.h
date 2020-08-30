// © GunSmoke, 2020

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override; //Postfix "override" makes sure, that 
	                                   //there is a "virtual void BeginPlay()"
									   //in some of the parent classes, and
									   // you are defining an overriding
									   // function, not new one.
};
