/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma region Includes
#include "Settings_Menu_Quick_Settings.h"
#include "../MISSING_Interview_lib/MISSING_Interview_Lib.h"
#pragma endregion

void MISSINGQuickSettingsMenu::DisplayMenu() {
	ImGui::Columns(2, NULL, false);

	DisplayQuickSettings();
	
	DisplayCodeSettingsUI();
	
}

#pragma region Displays
void MISSINGQuickSettingsMenu::DisplayQuickSettings() {
	quickRelatedSettingsTitle.ShowTitle();

	quickSettingDropDown.ShowButtons(&currentQuickSetting);


	ImGui::Spacing();
}
//Code setting thing probably needs its own class. I didn't expect to have more than one of these, so I didn't. Also time.
void MISSINGQuickSettingsMenu::DisplayCodeSettingsUI() {
	char buffer[256];
	memset(buffer, 0, 256);

	ImGui::Text("This is a text box for quickly setting your perfect settings between all MISSING games. \n"
		"No need to configure for every game. Just get one game perfect & copy the code!");

	ImGui::Text("Settings Code:");
	ImGui::SameLine();
	if (ImGui::InputText("##Input Text", buffer, 256)) {
		ImGui::Button("Click to set settings!");
	}
	ImGui::Spacing();
	if (ImGui::Button("Get Settings Code")) {
		switch (currentQuickSetting) {
		case BalanceTailored:
			currentCode = "Balanced";
			break;
		case GameTailored:
			currentCode = "Game";
			break;
		case CinematicTailored:
			currentCode = "Cinematic";
			break;
		case Custom:
			//Numbers won't work as delimiters when you print numbers to the screen.
			//I was considering the '~' symbol. 
			//Base 64 code or something might work too. This is a complex ideal.
			currentCode = "Custom";
			currentCode.append("1");
			currentCode.append(std::to_string(gameSettings->CodeGetCommonSettings()));
			currentCode.append("2");
			currentCode.append(std::to_string(uISettings->CodeGetCommonSettings()));
			currentCode.append("3");
			currentCode.append(std::to_string(videoSettings->CodeGetCommonSettings()));
			currentCode.append("4");
			currentCode.append(std::to_string(audioSettings->CodeGetCommonSettings()));
			currentCode.append("5");
			break;
		}
		//settingsCodeDisplayed = true;
	}
	ImGui::SameLine();

	//No time to get a proper code input system working
	//Every game would need to figure out how to interpret the code.
	//The code and interpretation systems would have to have error setup. IE "We never included Motion Blur in the code system before, but now we want to."
	if (ImGui::Button("Set Settings by Code")) {
		//Crashing isn't fun, so commented out.
		try {
			/*std::string bufferString = buffer;

			std::string difficulty = bufferString.substr(bufferString.find("1"), bufferString.find("2"));
			int difficultyValue = stoi(difficulty);
			gameSettings->CodeSetCommonSettings(difficultyValue);

			std::string compassEnabled = bufferString.substr(bufferString.find("2"), bufferString.find("3"));
			int compassEnabledValue = stoi(compassEnabled);
			uISettings->CodeSetCommonSettings(compassEnabledValue);

			std::string currentFOV = bufferString.substr(bufferString.find("3"), bufferString.find("4"));
			float currentFOVValue = stof(currentFOV);
			videoSettings->CodeSetCommonSettings(currentFOVValue);

			std::string masterVolume = bufferString.substr(bufferString.find("4"), bufferString.find("5"));
			float masterVolumeValue = stof(masterVolume);
			audioSettings->CodeSetCommonSettings(masterVolumeValue);
			*/
		}
		catch (int e) {
			currentCode = "Invalid Code!";
		}
	}

	//ImGui::Selectable(currentCode.c_str(), true); //ImGui doesn't really support copying text.
	ImGui::Text(currentCode.c_str());


}
#pragma endregion


#pragma region Quick_Change_Settings
void MISSINGQuickSettingsMenu::QuickChangeBalancedSetting() {
	gameSettings	->QuickChangeBalancedSetting();
	uISettings		->QuickChangeBalancedSetting();
	videoSettings	->QuickChangeBalancedSetting();
	audioSettings	->QuickChangeBalancedSetting();
}
void MISSINGQuickSettingsMenu::QuickChangeGameSetting() {
	gameSettings	->QuickChangeGameSetting();
	uISettings		->QuickChangeGameSetting();
	videoSettings	->QuickChangeGameSetting();
	audioSettings	->QuickChangeGameSetting();
}
void MISSINGQuickSettingsMenu::QuickChangeCinematicSetting() {
	gameSettings	->QuickChangeCinematicSetting();
	uISettings		->QuickChangeCinematicSetting();
	videoSettings	->QuickChangeCinematicSetting();
	audioSettings	->QuickChangeCinematicSetting();
}
#pragma endregion