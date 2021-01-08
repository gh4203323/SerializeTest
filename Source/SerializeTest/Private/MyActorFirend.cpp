// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorFirend.h"
#include <MyActor.h>

// Sets default values
AMyActorFirend::AMyActorFirend()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

//void AMyActorFirend::firendFunction(AMyActor* myActor)
//{
//	if (myActor)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("in firendFunction() ,ia = %d,sb = %s"), myActor->ia, *myActor->sb));
//	}
//}

// Called when the game starts or when spawned
void AMyActorFirend::BeginPlay()
{
	Super::BeginPlay();
	AActor* actor = GetWorld()->SpawnActor<AMyActor>();
	MyActor = Cast<AMyActor>(actor);
	if (MyActor)
	{
		firendFunction(MyActor);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("ia = %d,sb = %s"), MyActor->ia,*MyActor->sb));
	}
	
}

// Called every frame
void AMyActorFirend::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

