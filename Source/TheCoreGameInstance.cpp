#include "TheCoreGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Saves the players inventory and current position to a specified save slot
void UTheCoreGameInstance::SaveGame(UInventoryComponent* PlayerInventory, const FVector& PlayerPosition, int32 SaveSlotNum) {
    UTheCoreSaveGame* SaveData = Cast<UTheCoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UTheCoreSaveGame::StaticClass()));

    // Sets the player position and inventory data in the save object
    SaveData->PlayerPosition = PlayerPosition;
    SaveData->InventoryItems = PlayerInventory->SaveInventory();

    FString SaveSlotName = FString::Printf(TEXT("Slot%d"), SaveSlotNum);
    UGameplayStatics::SaveGameToSlot(SaveData, *SaveSlotName, 0);
}

// Loads the players inventory and position from a specified save slot
bool UTheCoreGameInstance::LoadGame(UInventoryComponent* PlayerInventory, FVector& NewPlayerPosition, int32 SaveSlotNum) {
    // Checks if the specified save slot exists
    FString SaveSlotName = FString::Printf(TEXT("Slot%d"), SaveSlotNum);
    if (!UGameplayStatics::DoesSaveGameExist(*SaveSlotName, 0)) {
        return false;
    }

    UTheCoreSaveGame* SavedData = Cast<UTheCoreSaveGame>(UGameplayStatics::LoadGameFromSlot(*SaveSlotName, 0));

    NewPlayerPosition = SavedData->PlayerPosition;

    if (PlayerInventory) {
        PlayerInventory->LoadInventory(SavedData->InventoryItems);
    }

    return true;
}

// Delete a specified save slot
void UTheCoreGameInstance::DeleteSave(int32 SaveSlotNum) {
    FString SaveSlotName = FString::Printf(TEXT("Slot%d"), SaveSlotNum);

    if (UGameplayStatics::DoesSaveGameExist(*SaveSlotName, 0)) {
        UGameplayStatics::DeleteGameInSlot(*SaveSlotName, 0);
    }
}
