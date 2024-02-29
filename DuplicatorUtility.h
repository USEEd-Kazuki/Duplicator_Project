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
	* �I�������A�Z�b�g�̕���
	* NumberOfDuplicates - �쐬���镡���̐�
	* bSave - �ۑ��̗v��
	**/
	UFUNCTION(CallInEditor)
	void DuplicateAsset(uint32 NumberOfDuplicates = 1, bool bSave = true);

private:

	/**
	* �X�N���[���ւ̃��b�Z�[�W�\��
	* @param Message - ���b�Z�[�W
	* @param Color - ���b�Z�[�W�Ɏg�p����F
	**/
	void PrintToScreen(FString Message, FColor Color);

	/**
	* ���[�U�[�ւ̃t�B�[�h�o�b�N
	* @param Method - �g�p���ꂽ���\�b�h
	* @param Counter - �ϊ����ꂽ�A�Z�b�g��
	**/
	void GiveFeedback(FString Method, uint32 Counter);
};
