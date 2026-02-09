// Defines the data structure for all item types.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemCategory.h"
#include "InventoryItemData.generated.h"

UCLASS(BlueprintType)
class COMP3421_API UInventoryItemData : public UDataAsset
{
    GENERATED_BODY()

public:

    // Display and organisation properties
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UTexture2D* DisplayIcon;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemCategory Category;

    // Item properties
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool IsStackable = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "bStackable")) // Can only be edited if the item is stackable
    int32 MaxStackNum = 99;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    bool IsUnique = false;
};
