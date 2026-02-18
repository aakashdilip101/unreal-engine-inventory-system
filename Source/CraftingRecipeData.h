// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItemData.h"
#include "CraftingRecipeData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class COMP3421_API UCraftingRecipeData : public UPrimaryDataAsset
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CraftableItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CraftableItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<UInventoryItemData*, int32> RequiredItems;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInventoryItemData* CraftedItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 CraftedItemQuantity = 1;
};
