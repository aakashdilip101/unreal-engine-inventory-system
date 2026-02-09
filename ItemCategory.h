// Enum inventory classification used for inventory filtering and grouping.

#pragma once

#include "CoreMinimal.h"
#include "ItemCategory.generated.h"

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
    None UMETA(DisplayName = "None"),
    Consumable UMETA(DisplayName = "Consumable"),
    Material UMETA(DisplayName = "Material"),
    Upgrade UMETA(DisplayName = "Upgrade"),
    Equipment UMETA(DisplayName = "Equipment"),
    Quest UMETA(DisplayName = "Quest")
};
