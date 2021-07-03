/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma region Includes
#include "Settings_Menu_Audio_Settings.h"
#include "../MISSING_Interview_lib/MISSING_Interview_Lib.h"
#pragma endregion

void MISSINGAudioSettingsMenu::DisplayMenu() {
	ImGui::Columns(2, NULL, false);

	DisplayVolumes();

	DisplayOtherSettings();

}

#pragma region Displays
void MISSINGAudioSettingsMenu::DisplayVolumes() {
	volumeRelatedSettingsTitle.ShowTitle();

	masterVolumeSlider.ShowSlider(&masterVolume, &minVolume, &maxVolume);
	musicVolumeSlider.ShowSlider(&musicVolume, &minVolume, &maxVolume);
	sFXVolumeSlider.ShowSlider(&sFXVolume, &minVolume, &maxVolume);
}
void MISSINGAudioSettingsMenu::DisplayOtherSettings() {
	otherRelatedSettingsTitle.ShowTitle();

	subtitlesCheckBox.ShowCheckbox(&subtitlesEnabled);
}
#pragma endregion

#pragma region Quick_Change_Settings
void MISSINGAudioSettingsMenu::QuickChangeBalancedSetting() {
	masterVolume	= 0.8f;
	musicVolume		= 0.8f;
	sFXVolume		= 0.8f;

	subtitlesEnabled = false;

}
void MISSINGAudioSettingsMenu::QuickChangeGameSetting() {
	masterVolume	= 1.0f;
	musicVolume		= 1.0f;
	sFXVolume		= 0.9f;

	subtitlesEnabled = true;
}
void MISSINGAudioSettingsMenu::QuickChangeCinematicSetting() {
	masterVolume	= 1.0f;
	musicVolume		= 0.7f;
	sFXVolume		= 0.9f;
	//Dialogue volume would be at 1.0f max

	subtitlesEnabled = false;
}
#pragma endregion
