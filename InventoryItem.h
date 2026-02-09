// Defines the data structure for individual inventory item instances.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "InventoryItem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
    GENERATED_BODY()

public:

    // Reference to the item data
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    UInventoryItemData* ItemData = nullptr;

    // Quantity of the item at runtime
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 Quantity = 0;

    FInventoryItem() = default;

    FInventoryItem(UInventoryItemData* InData, int32 InQuantity = 1)
        : ItemData(InData), Quantity(InQuantity)
    {
    }

    // Checks if the item is stackable
    bool IsStackable() const
    {
        return ItemData && ItemData->IsStackable;
    }

    // Checks if the item is unique (only one non stackable instance allowed in the inventory)
    bool IsUnique() const
    {
        return ItemData && ItemData->IsUnique;
    }
};
