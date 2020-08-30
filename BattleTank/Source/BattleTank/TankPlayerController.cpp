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

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());    //Gets the pawn of player controller and 
                                      // casts it to ATank.
}


