// Data structure for the inventory.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItem.h"
#include "InventoryComponent.generated.h"

// Delegate for inventory change events that blueprints (such as inventory UI) can bind to.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);

USTRUCT(BlueprintType)
struct FInventoryData {
    GENERATED_BODY()

    UPROPERTY()
    UInventoryItemData* ItemData;

    UPROPERTY()
    int32 Quantity;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COMP3421_API UInventoryComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UInventoryComponent();

    // Array of inventory items.
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FInventoryItem> Items;

    // Event for inventory changes.
    UPROPERTY(BlueprintAssignable)
    FOnInventoryChanged OnInventoryChanged;

    // Adds an item to the inventory
    UFUNCTION(BlueprintCallable)
    bool AddItem(UInventoryItemData* ItemData, int32 Quantity = 1);

    // Removes an item from the inventory
    UFUNCTION(BlueprintCallable)
    bool RemoveItem(UInventoryItemData* ItemData, int32 Quantity = 1);

    // Returns the quantity of a specified item type (returns 0 if not in the inventory)
    UFUNCTION(BlueprintCallable)
    int32 GetItemAmount(UInventoryItemData* ItemData) const;

    // Returns all items in a given catergory (Used for organisation in UI)
    UFUNCTION(BlueprintCallable)
    TArray<FInventoryItem> GetItemsByCategory(EItemCategory Category) const;

    // Returns the inventory in an appropriate format for saving
    UFUNCTION(BlueprintCallable)
    TArray<FInventoryData> SaveInventory() const;

    // Loads inventory from input save data
    UFUNCTION(BlueprintCallable)
    void LoadInventory(const TArray<FInventoryData>& SavedItems);

    // Clears the current inventory
    UFUNCTION(BlueprintCallable)
    void ClearInventory();


protected:
    virtual void BeginPlay() override;

private:
    // Finds the index of an item in the inventory array.
    int32 GetItemIndex(UInventoryItemData* ItemData) const;
};
