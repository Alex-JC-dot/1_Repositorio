#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BombermanGameMode.generated.h"

// Forward Declarations
class AMuro1;
class ABloque;

UCLASS()
class BOMBERMAN_API ABombermanGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABombermanGameMode();

protected:
    virtual void BeginPlay() override;

private:
    void GenerarMurosYBloques();
    void MoverObjetosAleatorios(TArray<AActor*>& Objetos, int32 Cantidad);  // 🔹 Se pasa por referencia
};
