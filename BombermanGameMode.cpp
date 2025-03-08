#include "BombermanGameMode.h"
#include "Muro1.h"
#include "Bloque.h"
#include "Engine/World.h"

void ABombermanGameMode::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("BeginPlay() de BombermanGameMode ejecutado correctamente."));
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("GameMode iniciado. Generando Muros y Bloques..."));

    GenerarMurosYBloques();
}

void ABombermanGameMode::GenerarMurosYBloques()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("GetWorld() es NULL, no se pueden generar los objetos."));
        return;
    }

    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Generando Muros y Bloques..."));

    int32 numMuros = 20;
    int32 numBloques = 10;
    float gridSize = 200.0f;
    FVector BasePosition = FVector(500.0f, 500.0f, 50.0f);


    TArray<AActor*> ObjetosMuros;
    TArray<AActor*> ObjetosBloques;

    TSubclassOf<AMuro1> MuroClass = AMuro1::StaticClass();
    TSubclassOf<ABloque> BloqueClass = ABloque::StaticClass();

    if (!MuroClass || !BloqueClass)
    {
        UE_LOG(LogTemp, Error, TEXT("No se pudo obtener la clase de Muro o Bloque."));
        return;
    }

    // Generar Muros
    for (int32 i = 0; i < numMuros; i++)
    {
        FVector Location = BasePosition + FVector((i % 5) * gridSize, (i / 5) * gridSize, 200.0f); // Se eleva en Z
        AMuro1* Muro = World->SpawnActor<AMuro1>(MuroClass, Location, FRotator::ZeroRotator);
        if (Muro)
        {
            ObjetosMuros.Add(Muro);
            UE_LOG(LogTemp, Warning, TEXT("Muro generado en X: %f, Y: %f, Z: %f"), Location.X, Location.Y, Location.Z);
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Muro en X: %f, Y: %f"), Location.X, Location.Y));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("ERROR: No se pudo generar un Muro en X: %f, Y: %f, Z: %f"), Location.X, Location.Y, Location.Z);
        }
    }

    // Generar Bloques
    for (int32 i = 0; i < numBloques; i++)
    {
        FVector Location = BasePosition + FVector((i % 5) * gridSize + gridSize / 2, (i / 5) * gridSize + gridSize / 2, 100.0f);
        ABloque* Bloque = World->SpawnActor<ABloque>(BloqueClass, Location, FRotator::ZeroRotator);
        if (Bloque)
        {
            ObjetosBloques.Add(Bloque);
            UE_LOG(LogTemp, Warning, TEXT("Bloque generado en X: %f, Y: %f, Z: %f"), Location.X, Location.Y, Location.Z);
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Bloque en X: %f, Y: %f"), Location.X, Location.Y));

        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("ERROR: No se pudo generar un Bloque en X: %f, Y: %f, Z: %f"), Location.X, Location.Y, Location.Z);
        }
    }
}