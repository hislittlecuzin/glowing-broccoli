/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma once

#pragma region Includes
#include<memory>
#include <string>
#include "../MISSING_Interview_lib/MISSING_Interview_lib.h"
#include "SettingsFormatter.h"
#pragma endregion


//Label is on the correct side for an editor. 
//Label is on the wrong side for a game. 
class idUTILITYCheckBox {
public:
	idUTILITYCheckBox(const char* newSettingLabel) {
		settingLabel = std::make_unique<const char*>(newSettingLabel);
	};

	//Labeled as checkbox & not just show so a tired programmer has a faster chance of catching the error. 
	//Plus show is the first part of the method/function, so intellisense will find it.
	void ShowCheckbox(bool* mainValue) {
		ImGui::Text(*settingLabel.get());
		ImGui::NextColumn();

		//Text is on the wrong side. Set the ID without having the text show up. 
		std::string currentCheckBoxLabel = "##";
		currentCheckBoxLabel.append(*settingLabel.get());

		ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetCheckBoxXOffset());
		ImGui::Checkbox(currentCheckBoxLabel.c_str(), mainValue);
		
		//Couldn't get a global debug variable working
		//ImGui::SameLine();
		//ImGui::Text(std::to_string(*mainValue).c_str());

		ImGui::NextColumn();
	};

private:
	std::unique_ptr<const char*> settingLabel;


};