// Fill out your copyright notice in the Description page of Project Settings.


#include "CraftingComponent.h"
#include "InventoryComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UCraftingComponent::UCraftingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCraftingComponent::BeginPlay()
{
	Super::BeginPlay();

	InventoryComponent = GetOwner()->FindComponentByClass<UInventoryComponent>();

	if (!InventoryComponent) {
		UE_LOG(LogTemp, Warning, TEXT("CraftingComponent found no inventory component to associate with."));
	}
	
}


bool UCraftingComponent::Craft(const UCraftingRecipeData* Recipe) {
    if (!Recipe || !InventoryComponent) {
        return false;
    }

    for (const auto& Requirement : Recipe->RequiredItems) {
        if (InventoryComponent->GetItemAmount(Requirement.Key) < Requirement.Value) {
            return false;
        }
    }

    for (const auto& Requirement : Recipe->RequiredItems) {
        InventoryComponent->RemoveItem(Requirement.Key, Requirement.Value);
    }

    InventoryComponent->AddItem(Recipe->CraftedItem, Recipe->CraftedItemQuantity);

    OnItemCrafted.Broadcast(Recipe);
    return true;
}
