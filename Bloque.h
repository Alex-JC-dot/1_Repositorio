#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

class UStaticMeshComponent;

UCLASS()
class BOMBERMAN_API ABloque : public AActor
{
    GENERATED_BODY()

public:
    ABloque();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Bloque")
    UStaticMeshComponent* MallaBloque;
};

