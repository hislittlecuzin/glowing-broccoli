/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#ifndef __SETTINGS_MENU_H_
#define __SETTINGS_MENU_H_

#pragma region Includes
#include "Sub_Setting_Menus/Settings_Menu_Quick_Settings.h"
#include "Sub_Setting_Menus/Settings_Menu_Game_Settings.h"
#include "Sub_Setting_Menus/Settings_Menu_UI_Settings.h"
#include "Sub_Setting_Menus/Settings_Menu_Video_Settings.h"
#include "Sub_Setting_Menus/Settings_Menu_Audio_Settings.h"
#pragma endregion


class MISSINGSettingsMenu {
public:
	MISSINGSettingsMenu() {
	}

	void		DisplayMenu();
	bool GoToMainMenu() {
		if (goToMainMenu) {
			goToMainMenu = false;
			return true;
		}
		return false;
	};

private:

	MISSINGQuickSettingsMenu quickSettings = MISSINGQuickSettingsMenu(&gameSettings, &uiSettings, &videoSettings, &audioSettings);
	MISSINGGameSettingsMenu gameSettings = MISSINGGameSettingsMenu();
	MISSINGUISettingsMenu uiSettings = MISSINGUISettingsMenu();
	MISSINGVideoSettingsMenu videoSettings = MISSINGVideoSettingsMenu();
	MISSINGAudioSettingsMenu audioSettings = MISSINGAudioSettingsMenu();

	void SettingMenuHeader();
	void DisplaySubMenuSelected();
	void DisplayMainMenuButton();

	bool goToMainMenu = false;
	int bottomOfScreen = 690;

	enum SubMenu {
		settingQuick,
		settingGame,
		settingUI,
		settingVideo,
		settingAudio,
	};
	SubMenu currentSettingsMenu = settingQuick;

	//Colors. 
	const ImVec4 titleColor = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
	const int pushedColors = 1;

};

extern MISSINGSettingsMenu * g_SettingsMenu;


#endif // !__SETTINGS_MENU_H_
