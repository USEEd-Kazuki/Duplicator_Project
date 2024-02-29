// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "DuplicatorUtility.generated.h"

/**
 * 
 */
UCLASS()
class PREFIXPROJECT_API UDuplicatorUtility : public UAssetActionUtility
{
	GENERATED_BODY()

public:

	/** 
	* 選択したアセットの複製
	* NumberOfDuplicates - 作成する複製の数
	* bSave - 保存の要否
	**/
	UFUNCTION(CallInEditor)
	void DuplicateAsset(uint32 NumberOfDuplicates = 1, bool bSave = true);

private:

	/**
	* スクリーンへのメッセージ表示
	* @param Message - メッセージ
	* @param Color - メッセージに使用する色
	**/
	void PrintToScreen(FString Message, FColor Color);

	/**
	* ユーザーへのフィードバック
	* @param Method - 使用されたメソッド
	* @param Counter - 変換されたアセット数
	**/
	void GiveFeedback(FString Method, uint32 Counter);
};
