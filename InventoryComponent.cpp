#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent() {
    PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay() {
    Super::BeginPlay();
}

// Returns the index of an item in the inventory, or INDEX_NONE if not found.
int32 UInventoryComponent::GetItemIndex(UInventoryItemData* ItemData) const {
    if (!ItemData) {
        return INDEX_NONE;
    }

    for (int32 i = 0; i < Items.Num(); i++) {
        if (Items[i].ItemData == ItemData) {
            return i;
        }
    }

    return INDEX_NONE;
}

// Adds a specified quantity of an item to the inventory.
bool UInventoryComponent::AddItem(UInventoryItemData* ItemData, int32 Quantity) {
    if (!ItemData || Quantity <= 0) {
        return false;
    }

    int32 ItemIndex = GetItemIndex(ItemData);

    // Doesn't add if the item is unique and already exists in the inventory.
    if (ItemData->IsUnique && ItemIndex != INDEX_NONE) {
        return false;
    }

    // If the item is stackable, increase the quantity but not beyond the MaxStackNum.
    if (ItemData->IsStackable) {
        if (ItemIndex != INDEX_NONE) {
            // Increase quantity but respect max stack
            Items[ItemIndex].Quantity = FMath::Clamp(Items[ItemIndex].Quantity + Quantity, 1, ItemData->MaxStackNum);
        }
        else {
            Items.Add(FInventoryItem(ItemData, FMath::Clamp(Quantity, 1, ItemData->MaxStackNum)));
        }
    } else {
        // If the item is not stackable, add a new entry.
        Items.Add(FInventoryItem(ItemData, 1));
    }

    // Broadcasts the inventory changed event.
    OnInventoryChanged.Broadcast();

    return true;
}

// Removes a specified quantity of an item from the inventory.
bool UInventoryComponent::RemoveItem(UInventoryItemData* ItemData, int32 Quantity) {
    int32 ItemIndex = GetItemIndex(ItemData);

    // If item doesn't exist in inventory return false.
    if (ItemIndex == INDEX_NONE) {
        return false;
    }

    // Retrieves a reference to the item in the inventory.
    FInventoryItem& Item = Items[ItemIndex];
    Item.Quantity -= Quantity;
        
    // If the quantity becomes 0, remove the entry from the inventory.
    if (Item.Quantity <= 0) {
        Items.RemoveAt(ItemIndex);
    }

    // Broadcasts the inventory changed event.
    OnInventoryChanged.Broadcast();

    return true;
}

// Returns all items in the inventory belonging to the specified category.
TArray<FInventoryItem> UInventoryComponent::GetItemsByCategory(EItemCategory Category) const {
    TArray<FInventoryItem> OutputItems;

    for (const FInventoryItem& Item : Items) {
        if (Item.ItemData && Item.ItemData->Category == Category) {
            OutputItems.Add(Item);
        }
    }

    return OutputItems;
}

// Returns the quantity of a specified item type in the inventory or 0 if it doesn't exist.
int32 UInventoryComponent::GetItemAmount(UInventoryItemData* ItemData) const {
    if (!ItemData) {
        return 0;
    }

    int32 Index = GetItemIndex(ItemData);
    if (Index != INDEX_NONE) {
        return Items[Index].Quantity;
    }

    return 0;
}
