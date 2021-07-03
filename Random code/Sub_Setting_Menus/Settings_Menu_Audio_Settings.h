/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma once

#pragma region Includes
#include "../Menu_Utilities/Check_Box_Menu_Utility.h"
#include "../Menu_Utilities/Title_Menu_Utility.h"
#include "../Menu_Utilities/Slider_Menu_Utility.h"

#pragma endregion

class MISSINGAudioSettingsMenu {
public:
	MISSINGAudioSettingsMenu() {
		//No drop down menus to configure.
	};

	void DisplayMenu();

	//Small enough scope for this project to leave in the Header
#pragma region Code_Set_Settings
	float CodeGetCommonSettings() {
		return masterVolume;
	}

	void CodeSetCommonSettings(float arg) {
		if (arg >= minVolume && arg <= maxVolume) {
			masterVolume = arg;
		}
		else {

		}
	}
#pragma endregion

	void QuickChangeBalancedSetting();
	void QuickChangeGameSetting();
	void QuickChangeCinematicSetting();

private:

	void DisplayVolumes();
	void DisplayOtherSettings();


#pragma region Volumes_Variables
	
	idUTILITYTitle volumeRelatedSettingsTitle = idUTILITYTitle("Volume Sliders:");

	float minVolume		= 0.0f;
	float maxVolume		= 1.0f;
	
	float masterVolume	= 0.8f;
	idUTILITYSlider masterVolumeSlider = idUTILITYSlider("Master Volume:");

	float musicVolume	= 0.8f;
	idUTILITYSlider musicVolumeSlider = idUTILITYSlider("Music Volume: ");

	float sFXVolume		= 0.8f;
	idUTILITYSlider sFXVolumeSlider = idUTILITYSlider("SFX Volume:   ");

#pragma endregion

#pragma region Other_Settings_Variables

	idUTILITYTitle otherRelatedSettingsTitle = idUTILITYTitle("Other Settings:");

	bool subtitlesEnabled = false;
	idUTILITYCheckBox subtitlesCheckBox = idUTILITYCheckBox("Enable Subtitles:");

#pragma endregion
};