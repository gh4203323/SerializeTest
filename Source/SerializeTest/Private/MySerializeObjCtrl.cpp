// Fill out your copyright notice in the Description page of Project Settings.


#include "MySerializeObjCtrl.h"
#include <MySerializeObj.h>
#include "Serialization/BufferArchive.h"


// Sets default values
AMySerializeObjCtrl::AMySerializeObjCtrl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMySerializeObjCtrl::SaveLoadData(FArchive& Ar, float& HealthToSaveOrLoad, int32& CurrentAmmoToSaveOrLoad, FVector& PlayerLocationToSaveOrLoad)
{
	//Save or load values
	Ar << HealthToSaveOrLoad;

	Ar << CurrentAmmoToSaveOrLoad;

	Ar << PlayerLocationToSaveOrLoad;

	Ar << *MySerializeObjRef;
}

void AMySerializeObjCtrl::SaveData()
{
	FBufferArchive ToBinary;
	SaveLoadData(ToBinary, Health, CurrentAmmo, RandomLocation);

	/*no data to save*/
	if (ToBinary.Num() <= 0)
		return;

	/*Save binaries to disk*/
	bool saveResult = FFileHelper::SaveArrayToFile(ToBinary, TEXT("D:/aa.txt"));
	
	/*empty the buffer's contents*/
	ToBinary.FlushCache();
	ToBinary.Empty();

	return;
}

void AMySerializeObjCtrl::LoadData()
{
	TArray<uint8> BinaryArray;

	//load disk data to binaries array
	if (!FFileHelper::LoadFileToArray(BinaryArray, TEXT("D:/aa.txt")))
		return;
	if (BinaryArray.Num() <= 0)
		return;

	FMemoryReader FromBinary = FMemoryReader(BinaryArray,true);
	FromBinary.Seek(0);
	SaveLoadData(FromBinary, Health, CurrentAmmo, RandomLocation);


	/*empty the buffer's contents*/
	FromBinary.FlushCache();
	BinaryArray.Empty();
	/*close the stream*/
	FromBinary.Close();
	return;
}

// Called when the game starts or when spawned
void AMySerializeObjCtrl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySerializeObjCtrl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

