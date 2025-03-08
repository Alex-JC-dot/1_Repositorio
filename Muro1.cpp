#include "Muro1.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AMuro1::AMuro1()
{
    PrimaryActorTick.bCanEverTick = false;

    MallaMuro1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMuro"));
    RootComponent = MallaMuro1;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMuro(TEXT("/Engine/BasicShapes/Cubee"));
    if (ObjetoMuro.Succeeded())
    {
        MallaMuro1->SetStaticMesh(ObjetoMuro.Object);
        MallaMuro1->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
        MallaMuro1->SetCollisionProfileName(TEXT("BlockAll"));
        MallaMuro1->SetVisibility(true);
        MallaMuro1->SetHiddenInGame(false);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ERROR: No se encontró la malla para Muro1."));
    }
}
void AMuro1::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Muro1 ha comenzado."));
}
void AMuro1::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

            