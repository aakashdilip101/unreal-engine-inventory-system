#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InventoryComponent.h"
#include "TheCoreSaveGame.generated.h"

UCLASS()
class COMP3421_API UTheCoreSaveGame : public USaveGame {
    GENERATED_BODY()

public:
    UPROPERTY()
    FVector PlayerPosition;

    UPROPERTY()
    TArray<FInventoryData> InventoryItems;
};
