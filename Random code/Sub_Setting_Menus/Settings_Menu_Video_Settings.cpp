/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma region Includes
#include "Settings_Menu_Video_Settings.h"
#include "../MISSING_Interview_lib/MISSING_Interview_Lib.h"
#pragma endregion

void MISSINGVideoSettingsMenu::DisplayMenu() {
	ImGui::Columns(2, NULL, false);
	
	DisplayModes();

	DisplayResolutions();
	
	DisplayPreferences();

	DisplayQualitys();
}

#pragma region Displays
void MISSINGVideoSettingsMenu::DisplayModes() {
	modeTitle.ShowTitle();
	videoModeDropDown.ShowButtons(&currentVideoMode);
}
void MISSINGVideoSettingsMenu::DisplayResolutions() {
	resolutionTitle.ShowTitle();
	aspectRatioDropDown.ShowButtons(&currentAspectRatio);

	switch (currentAspectRatio) {
	case SixteenByNine:
		sixteenByNineResolutionDropDown.ShowButtons(&currentSixteenByNineResolution);
		break;
	case FourByThree:
		fourByThreeResolutionDropDown.ShowButtons(&currentFourByThreeResolutions);
		break;
	default:
		break;
	}

}
void MISSINGVideoSettingsMenu::DisplayPreferences() {
	preferencesTitle.ShowTitle();

	motionBlurCheckBox.ShowCheckbox(&motionBlurEnabled);
	fOVSlider.ShowSlider(&fOV, &minFOV, &maxFOV);
	gammaSlider.ShowSlider(&gamma, &minGamma, &maxGamma);
}
void MISSINGVideoSettingsMenu::DisplayQualitys() {
	qualityTitle.ShowTitle();
	shadowQualityDropDown.ShowButtons(&currentShadowQuality);
}
#pragma endregion

#pragma region Quick_Change_Settings
void MISSINGVideoSettingsMenu::QuickChangeBalancedSetting() {
	currentVideoMode = Fullscreen;
	videoModeDropDown.QuickOverrideLabel("Fullscreen");

	fOV = 100.0f;
	gamma = 0.75f;

	currentShadowQuality = Medium;
	shadowQualityDropDown.QuickOverrideLabel("Medium");
}
void MISSINGVideoSettingsMenu::QuickChangeGameSetting() {
	currentVideoMode = WindowedFullscreen;
	videoModeDropDown.QuickOverrideLabel("Windowed Fullscreen");

	fOV = 120.0f;
	gamma = 1.0f;

	currentShadowQuality = Low;
	shadowQualityDropDown.QuickOverrideLabel("Low");
}
void MISSINGVideoSettingsMenu::QuickChangeCinematicSetting() {
	currentVideoMode = Fullscreen;
	videoModeDropDown.QuickOverrideLabel("Fullscreen");

	fOV = 95.0f;
	gamma = 0.5f;

	currentShadowQuality = High;
	shadowQualityDropDown.QuickOverrideLabel("High");
}
#pragma endregion