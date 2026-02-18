#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InventoryComponent.h"
#include "TheCoreSaveGame.h"
#include "TheCoreGameInstance.generated.h"

UCLASS()
class COMP3421_API UTheCoreGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:

    // Saves the players inventory and current position to a specified save slot
    UFUNCTION(BlueprintCallable)
    void SaveGame(class UInventoryComponent* PlayerInventory, const FVector& PlayerPosition, int32 SaveSlotNum);

    // Loads the players inventory and position from a specified save slot
    UFUNCTION(BlueprintCallable)
    bool LoadGame(class UInventoryComponent* PlayerInventory, FVector& NewPlayerPosition, int32 SaveSlotNum);

    // Deletes a specified save slot
    UFUNCTION(BlueprintCallable)
    void DeleteSave(int32 SaveSlotNum);
};
