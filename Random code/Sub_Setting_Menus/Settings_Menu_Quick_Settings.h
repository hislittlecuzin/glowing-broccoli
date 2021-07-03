/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma once

#pragma region Includes
#include "../Menu_Utilities/Drop_Down_Menu_Utility.h"
#include "../Menu_Utilities/Check_Box_Menu_Utility.h"
#include "../Menu_Utilities/Title_Menu_Utility.h"
#include "../Menu_Utilities/Slider_Menu_Utility.h"
#include <memory>

#include "Settings_Menu_Game_Settings.h"
#include "Settings_Menu_UI_Settings.h"
#include "Settings_Menu_Video_Settings.h"
#include "Settings_Menu_Audio_Settings.h"
#pragma endregion

class MISSINGQuickSettingsMenu {
public:
	MISSINGQuickSettingsMenu(MISSINGGameSettingsMenu* newGameMenu, MISSINGUISettingsMenu* newUIMenu, MISSINGVideoSettingsMenu* newVideoMenu, MISSINGAudioSettingsMenu* newAudioMenu) {
		gameSettings	= newGameMenu;
		uISettings		= newUIMenu;
		videoSettings	= newVideoMenu;
		audioSettings	= newAudioMenu;

		quickSettingDropDown.SetSpecificButtonID(BalanceTailored, "Balance", "Tailored for the best balance between gameplay & cinematics.");
		quickSettingDropDown.SetSpecificButtonID(GameTailored, "Game", "Tailored for people that just want to play.");
		quickSettingDropDown.SetSpecificButtonID(CinematicTailored, "Cinematic", "Tailored for people that want to forget it's just a game.");
		quickSettingDropDown.SetSpecificButtonID(Custom, "Custom", "You know what you want & it's not a preset.");
	};

	void DisplayMenu();

#pragma region Code_Set_Settings

	void SetToCustomMode() {
		currentQuickSetting = Custom;
		quickSettingDropDown.QuickOverrideLabel("Custom");
	}
	
#pragma endregion
	
private:

	//Used to modify the settings of the other menus when the setting is modified.
	void QuickChangeBalancedSetting();
	void QuickChangeGameSetting();
	void QuickChangeCinematicSetting();
	MISSINGGameSettingsMenu*  gameSettings;
	MISSINGUISettingsMenu*    uISettings;
	MISSINGVideoSettingsMenu* videoSettings;
	MISSINGAudioSettingsMenu* audioSettings;


	void DisplayQuickSettings();
	void DisplayCodeSettingsUI();


#pragma region Quick_Settings_Variables
	idUTILITYTitle quickRelatedSettingsTitle = idUTILITYTitle("Select a quick setting for some preset experiences.");

	enum QuickSettingChoice {
		BalanceTailored,
		GameTailored,
		CinematicTailored,
		Custom,
		QUICKsETTINGcHOICEcOUNT
	};
	int currentQuickSetting		= Custom;
	idUTILITYDropDownMenu quickSettingDropDown = idUTILITYDropDownMenu(QUICKsETTINGcHOICEcOUNT, "Quick Setting:", "Custom");
#pragma endregion


	bool settingsCodeEnabled	= false;
	std::string currentCode;

	
	
};