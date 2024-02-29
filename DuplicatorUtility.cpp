// Fill out your copyright notice in the Description page of Project Settings.


#include "DuplicatorUtility.h"
#include "EditorUtilityLibrary.h"
#include <EditorAssetLibrary.h>

void UDuplicatorUtility::DuplicateAsset(uint32 NumberOfDuplicates, bool bSave)
{
	TArray<FAssetData> AssetDataArray = UEditorUtilityLibrary::GetSelectedAssetData();

	uint32 Counter = 0;

	for (FAssetData AssetData : AssetDataArray)
	{
		// �w�肳�ꂽ�����̐������J��Ԃ�
		for (uint32 i = 0; i < NumberOfDuplicates; ++i)
		{
			// �V�����t�@�C�������쐬
			FString NewFilename = AssetData.AssetName.ToString().AppendChar('_').Append(FString::FromInt(i));
			// �V�����p�X���쐬
			FString NewPath = FPaths::Combine(AssetData.PackagePath.ToString(), NewFilename);
			if (ensure(UEditorAssetLibrary::DuplicateAsset(AssetData.ObjectPath.ToString(), NewPath)))
			{
				++Counter;
				if (bSave)
				{
					UEditorAssetLibrary::SaveAsset(NewPath, false);
				}
			}
		}
	}
	GiveFeedback("Duplicate ", Counter);
}

void UDuplicatorUtility::PrintToScreen(FString Message, FColor Color)
{
	if (ensure(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}

void UDuplicatorUtility::GiveFeedback(FString Method, uint32 Counter)
{
	FString Message = FString("No matching files found");
	FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
	if (Counter > 0)
	{
		Message = Method.AppendChar(' ');
		Message.AppendInt(Counter);
		Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));
	}
	PrintToScreen(Message, Color);
}
