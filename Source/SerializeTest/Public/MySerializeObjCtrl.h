// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySerializeObjCtrl.generated.h"

UCLASS()
class SERIALIZETEST_API AMySerializeObjCtrl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySerializeObjCtrl();

	void SaveLoadData(FArchive& Ar, float& HealthToSaveOrLoad, int32& CurrentAmmoToSaveOrLoad, FVector& PlayerLocationToSaveOrLoad);

	// ÄãºÃ
	UPROPERTY(EditAnywhere)
	class AMySerializeObj* MySerializeObjRef;

	UFUNCTION(CallInEditor,BlueprintCallable, Category = SaveLoad)
		void SaveData();

	UFUNCTION(CallInEditor,BlueprintCallable, Category = SaveLoad)
		void LoadData();

	UPROPERTY(EditAnywhere)
		float Health;

	UPROPERTY(EditAnywhere)
		int32 CurrentAmmo;

	UPROPERTY(EditAnywhere)
		FVector RandomLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
