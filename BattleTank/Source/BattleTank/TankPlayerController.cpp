// © GunSmoke, 2020


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay(); //Calls the original (not overridden) function of one of
                        // the parent classes.
    //Among other things, call "Event BeginPlay" of TankPlayerController_BP Blueprint.

    UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play"));

    auto ControlledTank = GetControlledTank();
    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possesing a tank."));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Tank Pawn Name is %s"),  *ControlledTank->GetName());
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());    //Gets the pawn of player controller and 
                                      // casts it to ATank.
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank())
        return;
    //Then ray-trace to find intersection aiming line with the landscape.
    FVector AimingLocation;
    GetSightRayAimLocation(&AimingLocation);

    UE_LOG(LogTemp, Warning, TEXT("AimingLocation = %s"), *(AimingLocation.ToString()));
}

//Get world location of linetrace through crosshair. True, if line of sight has an intersection with the world.
bool ATankPlayerController::GetSightRayAimLocation(FVector* AimLocation) const
{
    //get camera's coords

    //get direction to crosshair: considering camera direction is screen center, 
    //  calculate crosshair direction as camera direction + (crosshair_coords_from_center * angle_per_pixel)
    //  angle_per_pixel is known by the screen size and current camera angle of view (FOV)

    //line trace from camera coords in direction of crosshair
    //return true, if the intersection exists, and false otherwise.


    //acquire current screen size in pixels
    int32 ViewportWidth, ViewportHeight;
    GetViewportSize(ViewportWidth, ViewportHeight);

    //Crosshair screen coords
    auto CrosshairPosition = FVector2D(ViewportWidth * CrosshairX, ViewportHeight * CrosshairY);

    //Get camera coords and direction

    //For testing modify of the out parameter:
    *AimLocation = FVector(1.0);
    return false;
}
