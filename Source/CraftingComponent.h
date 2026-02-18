// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CraftingRecipeData.h"
#include "CraftingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCrafted, const UCraftingRecipeData*, Recipe);


UCLASS( ClassGroup=(Gameplay), meta=(BlueprintSpawnableComponent) )
class COMP3421_API UCraftingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCraftingComponent();

	UFUNCTION(BlueprintCallable)
	bool Craft(const UCraftingRecipeData* Recipe);

	UPROPERTY(BlueprintAssignable, Category = "Crafting")
	FOnItemCrafted OnItemCrafted;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	class UInventoryComponent* InventoryComponent;
		
};
