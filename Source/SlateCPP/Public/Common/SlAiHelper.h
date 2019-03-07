// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <TimerManager.h>

/**
 * Debug信息类
 */

namespace SlAiHelper
{
	FORCEINLINE void Debug(FString Message, float Duration = 3.f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Yellow, Message);
		}
	}

	//播放音乐的时候调用此模板
	template<class UserClass>
	//内联函数
	FORCEINLINE FTimerHandle PlayerSoundAndCall(UWorld* World,const FSlateSound Sound,UserClass* InUserObject,typename FTimerDelegate::TRawMethodDelegate<UserClass>::FMethodPtr InMethod)
	{
		FSlateApplication::Get().PlaySound(Sound);
		FTimerHandle Result;
		const float SoundDuration = FMath::Max(FSlateApplication::Get().GetSoundDuration(Sound), 0.1f);
		FTimerDelegate CallBack;
		CallBack.BindRaw(InUserObject, InMethod);
		World->GetTimerManager().SetTimer(Result, CallBack, SoundDuration, false);
		return Result;
	}




}
