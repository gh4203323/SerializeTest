// Fill out your copyright notice in the Description page of Project Settings.


#include "MySerializeObj.h"

// Sets default values
AMySerializeObj::AMySerializeObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	life = 10;
}

// Called when the game starts or when spawned
void AMySerializeObj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySerializeObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FArchive& operator<<(FArchive& Ar, AMySerializeObj& MySerializeObjRef)
{
	Ar << MySerializeObjRef.life;

	return Ar;
}
