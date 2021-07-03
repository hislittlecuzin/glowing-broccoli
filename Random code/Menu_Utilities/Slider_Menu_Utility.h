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
#include "../MISSING_Interview_lib/MISSING_Interview_lib.h"
#include "SettingsFormatter.h"
#pragma endregion

class idUTILITYSlider {
public:
	idUTILITYSlider(const char* newSettingLabel) {
		settingLabel = std::make_unique<const char*>(newSettingLabel);
		
		currentSliderCheckboxLabel.append(*settingLabel.get());
		currentSliderLabel.append(*settingLabel.get());
	};
	
	void ShowSlider(float* mainValue, float* minVal, float* maxVal) {
		ImGui::Text(*settingLabel);
		ImGui::SameLine();

		//Load precise slider. Can type exact value.
		if (precise) {
			ImGui::InputFloat(currentSliderLabel.c_str(), mainValue, precisionLevel);
		}
		//Load coarse slider. Easier to use. 
		else {
			ImGui::SliderFloat(currentSliderLabel.c_str(), mainValue, *minVal, *maxVal);
		}
		ImGui::NextColumn();

		ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetSliderPrecisionXOffset());
		ImGui::Checkbox(currentSliderCheckboxLabel.c_str(), &precise);

		//Couldn't get a Global debug variable working.
		//ImGui::SameLine();
		//ImGui::Text(std::to_string(*mainValue).c_str());
		
		ImGui::NextColumn();

		//Override excess control from precision mode.
		if (*mainValue < *minVal) {
			*mainValue = *minVal;
		}
		else if (*mainValue > *maxVal) {
			*mainValue = *maxVal;
		}
	};


private:

	bool precise = false;
	const float precisionLevel = .1f; //There's + & - buttons. Felt this was good enough if it was controlled by a controller.

	std::unique_ptr<const char*> settingLabel;

	//Needed to prevent precise toggles from having the same ID. 
	std::string currentSliderCheckboxLabel = "Precise Adjustment##";
	std::string currentSliderLabel = "##";
};