// © GunSmoke, 2020

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override; //Postfix "override" makes sure, that 
	                                   //there is a "virtual void BeginPlay()"
									   //in some of the parent classes, and
									   // you are defining an overriding
									   // function, not new one.
	ATank* GetPlayerTank() const;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
