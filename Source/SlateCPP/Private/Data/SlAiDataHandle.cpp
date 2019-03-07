// Fill out your copyright notice in the Description page of Project Settings.

#include "SlAiDataHandle.h"
#include <Internationalization.h>
#include "SlAiSingleton.h"
#include "SlAiJsonHandle.h"
#include "SlAiHelper.h"
#include "SlAiStyle.h"
#include "SlAiMenuWidgetStyle.h"
#include <Sound/SoundCue.h>


TSharedPtr<SlAiDataHandle> SlAiDataHandle::DataInstance = nullptr;


SlAiDataHandle::SlAiDataHandle()
{
	//初始化
	//CurrentCulture = ECultureTeam::ZH;
	//初始化音量
	//MusicVolume = 0.5f;
	//SoundVolume = 0.5f;
	//初始化存档数据
	InitRecordData();
	//初始化音乐数据
	InitializedMenuAudio();

}

void SlAiDataHandle::Initialize()
{
	if (!DataInstance.IsValid())
	{
		DataInstance = Create();
	}
}

TSharedPtr<SlAiDataHandle> SlAiDataHandle::Get()
{
	Initialize();
	return DataInstance;
}

void SlAiDataHandle::ChangeLocalizationCulture(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::ZH:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	default:
		break;
	}
	//赋值
	CurrentCulture = Culture;
	//更新存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);

}

void SlAiDataHandle::ResetMenuVolume(float MusicVol, float SoundVol)
{
	if (MusicVol > 0)
	{
		MusicVolume = MusicVol;
		//循环设置背景音量
		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Music"))->CreateIterator());It;++It)
		{
			//设置音量
			(*It)->VolumeMultiplier = MusicVolume;
		}
	}
	if (SoundVol > 0)
	{
		SoundVolume = SoundVol;
		//循环设置音效音量
		for (TArray<USoundCue*>::TIterator It(MenuAudioResource.Find(FString("Sound"))->CreateIterator()); It; ++It)
		{
			//指针的指针
			(*It)->VolumeMultiplier = SoundVolume;
		}
	}
	//更新存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->UpdateRecordData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCulture), MusicVolume, SoundVolume, &RecordDataList);

}

TSharedPtr<SlAiDataHandle> SlAiDataHandle::Create()
{
	TSharedRef<SlAiDataHandle> DataRef = MakeShareable(new SlAiDataHandle());
	return DataRef;
}

template<typename TEnum>
FString SlAiDataHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return FString("InValid");
	}
	return EnumPtr->GetNameStringByIndex((int32)Value);
}

template<typename TEnum>
TEnum SlAiDataHandle::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}

void SlAiDataHandle::InitRecordData()
{
	//初始化存档名
	RecordName = FString("");
	//获取语言
	FString Culture;
	//读取存档数据
	SlAiSingleton<SlAiJsonHandle>::Get()->RecordDataJsonRead(Culture, MusicVolume, SoundVolume, RecordDataList);
	//初始化语言
	ChangeLocalizationCulture(GetEnumValueFromString<ECultureTeam>(FString("ECultureTeam"), Culture));
}

void SlAiDataHandle::InitializedMenuAudio()
{
	//获取MenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	//添加资源文件到资源列表
	TArray<USoundCue*> MusicList;
	MusicList.Add(Cast<USoundCue>(MenuStyle->MenuBackGroundMusic.GetResourceObject()));

	TArray<USoundCue*> SoundList;
	SoundList.Add(Cast<USoundCue>(MenuStyle->StartGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->ExitGameSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenuStyle->MenuItemChangeSound.GetResourceObject()));

	//添加资源到Map
	MenuAudioResource.Add(FString("Music"), MusicList);
	MenuAudioResource.Add(FString("Sound"), SoundList);

	//重置一下声音
	ResetMenuVolume(MusicVolume, SoundVolume);
}

