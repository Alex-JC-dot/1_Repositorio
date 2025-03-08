#include "Bloque.h"
#include "Components/StaticMeshComponent
    PrimaryActorTick.bCanEverTick = true;  // Habilita Tick()

    MallaBloque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque"));
    RootComponent = MallaBloque;

    static ConstructorHelpers::FObjectFind<UStaticMesh> ObjetoBloque(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
    if (ObjetoBloque.Succeeded())er
    {.h"
#include "UObject/ConstructorHelpers.h"

// Constructor de la clase ABloque
ABloque::ABloque()
{
        MallaBloque->SetStaticMesh(ObjetoBloque.Object);
    }
}

void ABloque::BeginPlay()
{
    Super::BeginPlay();
}

void ABloque::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}