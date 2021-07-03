/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma region Includes
#include "Settings_Menu_Game_Settings.h"
#include "../MISSING_Interview_lib/MISSING_Interview_Lib.h"
#pragma endregion

void MISSINGGameSettingsMenu::DisplayMenu() {
	ImGui::Columns(2, NULL, false);

	DisplayTips();

	DisplayMainGameOptions();

	DisplayControls();

}

#pragma region Displays
void MISSINGGameSettingsMenu::DisplayTips() {
	tipsRelatedSettingsTitle.ShowTitle();
	tutorialsCheckBox.ShowCheckbox(&tutorialsEnabled);
	inGameTipsCheckBox.ShowCheckbox(&inGameTipsEnabled);
}
void MISSINGGameSettingsMenu::DisplayMainGameOptions() {
	mainGameRelatedSettingsTitle.ShowTitle();

	//difficulty drop down
	difficultyDropDown.ShowButtons(&currentDifficulty);

	//Checkboxes
	autoSwitchWeaponsOnEmptyCheckBox.ShowCheckbox	(&autoSwitchWeaponsOnEmptyEnabled);
	autoSwitchWeaponsOnNewCheckBox.ShowCheckbox		(&autoSwitchWeaponsOnNewEnabled);
	screenShakeCheckBox.ShowCheckbox				(&screenShakeEnabled);
}
void MISSINGGameSettingsMenu::DisplayControls() {
	controlRelatedSettingsTitle.ShowTitle();
	basicControlMethodDropDown.ShowButtons(&currentControlMethod);

	//No need to mess with keyboard/controller settings when you're not using it.
	if (currentControlMethod == Keyboard) {
		keyboardRelatedSettingsTitle.ShowTitle();

		mouseHorizontalSensitivitySlider.ShowSlider	(&mouseHorizontalSensitivity,	&minMouseSensitivity,	&maxMouseSensitivity);
		mouseVerticalSensitivitySlider.ShowSlider	(&mouseVerticalSensitivity,		&minMouseSensitivity,	&maxMouseSensitivity);

		invertKeyboardLookCheckBox.ShowCheckbox(&invertKeyboardLookEnabled);
	}
	else {
		controllerRelatedSettingsTitle.ShowTitle();

		invertControllerLookCheckBox.ShowCheckbox			(&invertControllerLookEnabled);
		controllerVibrationCheckBox.ShowCheckbox			(&controllerVibrationEnabled);
		controllerAimAssistDropDown.ShowButtons(&currentControllerAimAssist);

		controllerHorizontalSensitivitySlider.ShowSlider	(&controllerHorizontalSensitivity,	&minControllerSensitivity,	&maxControllerSensitivity);
		controllerVerticalSensitivitySlider.ShowSlider		(&controllerVerticalSensitivity,		&minControllerSensitivity,	&maxControllerSensitivity);
	}
	
}

#pragma endregion

#pragma region Quick_Change_Settings
void MISSINGGameSettingsMenu::QuickChangeBalancedSetting() {
	tutorialsEnabled = true;
	inGameTipsEnabled = true; //Change to essential later

	currentDifficulty = Medium;
	difficultyDropDown.QuickOverrideLabel("Medium");
	autoSwitchWeaponsOnEmptyEnabled = true;
	autoSwitchWeaponsOnNewEnabled = true;

	screenShakeEnabled = true;

	invertKeyboardLookEnabled = false;

	invertControllerLookEnabled = false;
	controllerVibrationEnabled = true;
	currentControllerAimAssist = Some;
	controllerAimAssistDropDown.QuickOverrideLabel("Some");
}
void MISSINGGameSettingsMenu::QuickChangeGameSetting() {
	tutorialsEnabled = true;
	inGameTipsEnabled = true; //Change to idiot later

	currentDifficulty = Medium;
	difficultyDropDown.QuickOverrideLabel("Medium");

	autoSwitchWeaponsOnEmptyEnabled = true;
	autoSwitchWeaponsOnNewEnabled = true;

	screenShakeEnabled = true;

	invertKeyboardLookEnabled = false;

	invertControllerLookEnabled = false;
	controllerVibrationEnabled = true;
	currentControllerAimAssist = Some;
	controllerAimAssistDropDown.QuickOverrideLabel("Some");
}
void MISSINGGameSettingsMenu::QuickChangeCinematicSetting() {
	tutorialsEnabled = false; //Gameifies the game. Breaks immersion.
	inGameTipsEnabled = true; //Change to essential later. Prevents player from remembering it's a game if they can't figure out where to go.

	currentDifficulty = Easy;
	difficultyDropDown.QuickOverrideLabel("Easy");
	autoSwitchWeaponsOnEmptyEnabled	= false;
	autoSwitchWeaponsOnNewEnabled		= false;

	screenShakeEnabled = true;

	invertKeyboardLookEnabled = false;

	invertControllerLookEnabled = false;
	controllerVibrationEnabled = true;
	currentControllerAimAssist = Maximum;
	controllerAimAssistDropDown.QuickOverrideLabel("Maximum");
}
#pragma endregion