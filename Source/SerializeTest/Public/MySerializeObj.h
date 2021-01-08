// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySerializeObj.generated.h"

UCLASS()
class SERIALIZETEST_API AMySerializeObj : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySerializeObj();

	friend FArchive& operator<<(FArchive& Ar, AMySerializeObj& MySerializeObjRef);

	UPROPERTY(EditAnywhere)
		int life;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
