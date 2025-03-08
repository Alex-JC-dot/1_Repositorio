#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro1.generated.h"

class UStaticMeshComponent;

UCLASS()
class BOMBERMAN_API AMuro1 : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AMuro1();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // Propiedad correctamente definida
    UPROPERTY(VisibleAnywhere, Category = "Muro")
    UStaticMeshComponent* MallaMuro1;
};
