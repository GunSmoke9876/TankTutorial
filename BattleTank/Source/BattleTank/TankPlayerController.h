// © GunSmoke, 2020

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
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
									   // Called every frame
	void Tick(float DeltaTime) override;


	private:
	//Makes tank to rotate it's barrel to crosshair's direction.
	void AimTowardsCrosshair();

	//Retuns coords of intersection line of sight with landscape.
	bool GetSightRayAimLocation(FVector &AimLocation) const; 

	//Get a look direction through a point on the screen
	bool GetLookDirection(FVector2D PointOnScreen, FVector& SightStart, FVector& LookDirection) const;

	//Get world position of the intersection point of specified ray with some object of the world
	bool GetLookVectorAimLocation(FVector LookDirection, FVector LookStartLocation, FVector& LookLocation) const;

	//Screen coordinate X of crosshair, set up in TankPlayerController_BP blueprint (0..1).
	UPROPERTY(EditAnywhere)
	float CrosshairX = 0.5;
	
	//Screen coordinate Y of crosshair, set up in TankPlayerController_BP blueprint (0..1).
	UPROPERTY(EditAnywhere)
	float CrosshairY = 0.4;

	//Limit of ray-tracing, when getting aimed point of the world
	UPROPERTY(EditAnywhere)
	float MaxAimDistance = 1000000.0;
};
