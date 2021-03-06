// © GunSmoke, 2020


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay(); //Calls the original (not overridden) function of one of
                        // the parent classes.
 

    UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));

    auto ControlledTank = GetControlledTank();
    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Error, TEXT("TankAIController not possesing a tank."));
        return;
    }
    UE_LOG(LogTemp, Warning, TEXT("AI Tank Pawn Name is %s"),  *ControlledTank->GetName());

    auto TargetTank = GetPlayerTank();
    if(!TargetTank)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to find it's target!"));
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("This tank's target is %s"),  *TargetTank->GetName());

}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());    //Gets the pawn of AI controller and 
                                      // casts it to ATank.
}

ATank* ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ATank* TargetTank = GetPlayerTank();
    ATank* ControlledTank = GetControlledTank();
    ControlledTank->AimAt(TargetTank->GetActorLocation());
}

