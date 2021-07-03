/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma once

#pragma region Includes
#include <memory>
#include <vector>
#include <string>
#include "../MISSING_Interview_lib/MISSING_Interview_lib.h"
#include "SettingsFormatter.h"
#pragma endregion
/*

Setup:::
Construct the object in its declaration.
In the menu's header file, go into the class' constructor & call "SetSpecificButtonID" for every button option.
Don't include the Count value.@@@@@@@@@@@@@@

Implement:::
Go to the CPP file & in the method where you show the UI,
Put this object in the argument of the switch statement.
Set cases for every option.
Have each respective case set the value for their respective value.

*/
class idUTILITYDropDownMenu {
public:
#pragma region Setup
	idUTILITYDropDownMenu(int newAmountOfOptions, const char* newLabel, const char* newCurrentSetting) {

		options = newAmountOfOptions;
		for (int i = 0; i < options; i++) {
			const char* val = "Null";
			buttonIDs.push_back(std::make_unique<const char*>(val));
			settingExplanations.push_back(std::make_unique<const char*>(val));
		}
		settingLabel = std::make_unique<const char*>(newLabel);
		currentSettingText = std::make_unique<const char*>(newCurrentSetting);
	};

	/// <summary> Used to give information to the buttons.
	///</summary>
	void SetSpecificButtonID(int index, const char* newIDToSet, const char* newSettingExplanation) {
		buttonIDs.at(index) = std::make_unique<const char*>(newIDToSet);
		settingExplanations.at(index) = std::make_unique<const char*>(newSettingExplanation);
	};
#pragma endregion

	/// <summary> Return int so you can figure out what the answer to what the setting selected is. 
	///</summary>
	int ShowButtons(int* mainValue) {
		ImGui::Text(*settingLabel.get());
		ImGui::NextColumn();

		//Open select menu
		if (GetSelecting()) {

			ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetDropDownXOffset());
			ImGui::Text(*currentSettingText.get());

			ImGui::PushStyleColor(ImGuiCol_Text, choosingText);
			
			ImGui::NextColumn();
			for (int i = 0; i < options; i++) {
				ImGui::Text(*settingExplanations.at(i).get());
				ImGui::NextColumn();
				ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetDropDownXOffset());
				if (ImGui::Button(*buttonIDs.at(i).get())) {
					SetSelecting(false);
					currentSettingText = std::make_unique<const char*>(*buttonIDs[i].get());

					ImGui::PopStyleColor(pushedColors);
					*mainValue = i; //Yes, I know. The switch statements are redundant. I don't have time to remove the switch statements again. It's time for bed!
					return i;
				}
				ImGui::NextColumn();
			}
		}
		//Only show the current selection
		else {
			ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetDropDownXOffset());
			ImGui::PushStyleColor(ImGuiCol_Text, defaultText);
			if (ImGui::Button(*currentSettingText.get())) {
				SetSelecting(true);
			}
			
			//Couldn't get a global debug variable working
			//ImGui::SameLine();
			//ImGui::Text(std::to_string(*mainValue).c_str());
			
			ImGui::NextColumn();
		}

		ImGui::PopStyleColor(pushedColors);
		return -1;
	}

#pragma region Getters_Then_Setters
	int GetAmountOfOptions() { return options; };
	bool GetSelecting() { return selectingAnOption; };

	//No longer needed but written in code in a few places. May not have time to cleanup. 
	void SetSelecting(bool newVal) { selectingAnOption = newVal; };

#pragma endregion

	void QuickOverrideLabel(char* newVal) {
		currentSettingText = std::make_unique<const char*>(newVal);
	};
	
private:
	
	//What setting this is. 
	std::unique_ptr<const char*> settingLabel;
	
	//How many options there are. 
	int options = 0;
	//What the name of the setting is & what it does.
	std::vector<std::unique_ptr<const char*>> buttonIDs;
	std::vector<std::unique_ptr<const char*>> settingExplanations;

	//Check if in the process of choosing a new option.
	bool selectingAnOption = false;

	//Remembers the text to label what the current setting is.
	std::unique_ptr<const char*> currentSettingText; //Can probably optimise to reflect index of "buttonIDs." Kein Zeit

	//Colour stuff
	const ImVec4 defaultText = ImColor(1.0f, 1.0f, 1.0f, 1.0f);
	const ImVec4 choosingText = ImColor(1.0f, 1.0f, 0.2f, 1.0f);
	const int pushedColors = 1; //Can only push 1 color within the context. MUST also push 1 color.

};