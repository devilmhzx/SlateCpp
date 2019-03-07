// Fill out your copyright notice in the Description page of Project Settings.

#include "SlAiJsonHandle.h"
#include "SlAiHelper.h"

SlAiJsonHandle::SlAiJsonHandle()
{
	RecordDataFileName = FString("RecordData.json");

	RelativePath = FString("Res/ConfigData/");

}

void SlAiJsonHandle::RecordDataJsonRead(FString& Culture, float& MusicVolume, float& SoundVolume, TArray<FString>& ReacordDataList)
{
	/*新建一个FString变量来获取JS文件的实例*/
	FString JsonValue;
	/*LoadStringFromFile函数可将JS文件复制给Fstring实例变量JsonValue*/
	LoadStringFromFile(RecordDataFileName, RelativePath, JsonValue);
	/*定义一个共享指针的数组来保存JS文件内的数据*/
	TArray<TSharedPtr<FJsonValue>> JsonParsed;
	/*将JsonValue复制赋给新建指针JsonReader*/
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);
	/*通过FJsonSerializer::Deserialize解析，将*JsonReader值赋给JsonParsed数组*/
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		/*获取解析后的数据*/
		Culture = JsonParsed[0]->AsObject()->GetStringField(FString("Culture"));	/*对应JS文件内第一条信息*/
		MusicVolume = JsonParsed[1]->AsObject()->GetNumberField(FString("MusicVolume"));
		SoundVolume = JsonParsed[2]->AsObject()->GetNumberField(FString("SoundVolume"));
		//获取存档数据数组中内容
		TArray<TSharedPtr<FJsonValue>> RecordDataArray = JsonParsed[3]->AsObject()->GetArrayField(FString("RecordData"));
		for (int i = 0; i < RecordDataArray.Num(); ++i)
		{
			FString RecordDataName = RecordDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			//将值传入参数数组中
			ReacordDataList.Add(RecordDataName);
		}

	}
	else
	{
		SlAiHelper::Debug(FString("Deserialize Failed!"));
	}
}

void SlAiJsonHandle::UpdateRecordData(FString Culture, float MusicVolume, float SoundVolume, TArray<FString>* RecordDataList)
{
	TSharedPtr<FJsonObject> JSonObject = MakeShareable(new FJsonObject);

	TArray<TSharedPtr<FJsonValue>> BaseDataArray;

	TSharedPtr<FJsonObject> CultureObject = MakeShareable(new FJsonObject);
	CultureObject->SetStringField("Culture", Culture);
	TSharedPtr<FJsonValueObject> CultureValue = MakeShareable(new FJsonValueObject(CultureObject));

	TSharedPtr<FJsonObject> MusicVolumeObject = MakeShareable(new FJsonObject);
	MusicVolumeObject->SetNumberField("MusicVolume", MusicVolume);
	TSharedPtr<FJsonValueObject> MusicVolumeValue = MakeShareable(new FJsonValueObject(MusicVolumeObject));

	TSharedPtr<FJsonObject> SoundVolumeObject = MakeShareable(new FJsonObject);
	SoundVolumeObject->SetNumberField("SoundVolume", SoundVolume);
	TSharedPtr<FJsonValueObject> SoundVolumeValue = MakeShareable(new FJsonValueObject(SoundVolumeObject));

	TArray<TSharedPtr<FJsonValue>> RecordDataArray;

	for (int i =0;i<RecordDataList->Num();++i)
	{
		TSharedPtr<FJsonObject> RecordItem = MakeShareable(new FJsonObject);
		RecordItem->SetStringField(FString::FromInt(i), (*RecordDataList)[i]);
		TSharedPtr<FJsonValueObject> RecordDataValue = MakeShareable(new FJsonValueObject(RecordItem));
		RecordDataArray.Add(RecordDataValue);
	}

	TSharedPtr<FJsonObject> RecordDataObject = MakeShareable(new FJsonObject);
	RecordDataObject->SetArrayField("RecordData", RecordDataArray);
	TSharedPtr<FJsonValueObject> RecordDataValue = MakeShareable(new FJsonValueObject(RecordDataObject));

	BaseDataArray.Add(CultureValue);
	BaseDataArray.Add(MusicVolumeValue);
	BaseDataArray.Add(SoundVolumeValue);
	BaseDataArray.Add(RecordDataValue);

	JSonObject->SetArrayField("T", BaseDataArray);

	FString JsonStr;
	GetFStringInJsonData(JSonObject, JsonStr);

	//修改前输出测试
	//SlAiHelper::Debug(FString("Origin Str:" + JsonStr), 60.f);

	//去掉多余字符
	JsonStr.RemoveAt(0, 8);
	JsonStr.RemoveFromEnd(FString("}"));

	//修改后输出测试
	//SlAiHelper::Debug(FString("Final Str:" + JsonStr), 60.f);

	//写入文件
	WriteFileWithJsonData(JsonStr, RelativePath, RecordDataFileName);
}

bool SlAiJsonHandle::LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString)
{
	//先判断文件夹是否存在
	if (!FileName.IsEmpty())
	{
		//获取绝对路径
		FString AbsoPath = FPaths::ProjectContentDir() + RelaPath + FileName;
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString, *AbsoPath))
			{
				return true;
			}
			else
			{
				//加载不成功
				SlAiHelper::Debug(FString("Load Error") + AbsoPath);
			}
		}
		else
		{
			//输出文件不存在
			SlAiHelper::Debug(FString("File Not Exist") + AbsoPath);
		}

	}
	return false;
}

bool SlAiJsonHandle::GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr)
{
	if (JsonObj.IsValid()&&JsonObj->Values.Num()>0)
	{
		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonStr);
		FJsonSerializer::Serialize(JsonObj.ToSharedRef(), JsonWriter);
		return true;
	} 
	return false;

}

bool SlAiJsonHandle::WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName)
{
	if (!JsonStr.IsEmpty())
	{
		if (!FileName.IsEmpty())
		{
			FString AbsoPath = FPaths::ProjectContentDir() + RelaPath + FileName;
			//保存数据
			if (FFileHelper::SaveStringToFile(JsonStr,*AbsoPath))
			{
				return true;
			}
			else
			{
				SlAiHelper::Debug(FString("Save") + AbsoPath + FString("-->Failed"), 10.f);
				return false;
			}
		}
	}
	return false;
}

