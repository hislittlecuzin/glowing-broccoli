/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/

#pragma region Includes
#include "Settings_Menu_UI_Settings.h"
#include "../MISSING_Interview_lib/MISSING_Interview_Lib.h"
#pragma endregion

void MISSINGUISettingsMenu::DisplayMenu() {
	ImGui::Columns(2, NULL, false);

	DisplayOpacitys();

	DisplayToggles();
	
}

#pragma region Displays
void MISSINGUISettingsMenu::DisplayOpacitys() {
	opacityRelatedSettingsTitle.ShowTitle();

	hudOpacitySlider.ShowSlider(&hudOpacity, &minOpacity, &maxOpacity);
}
void MISSINGUISettingsMenu::DisplayToggles() {
	toggleRelatedSettingsTitle.ShowTitle();

	crosshairDropDown.ShowButtons(&currentCrosshair);
	compassEnabledCheckBox.ShowCheckbox(&compassEnabled);
	notificationsCheckBox.ShowCheckbox(&notificationsEnabled);
}
#pragma endregion

#pragma region Quick_Change_Settings
void MISSINGUISettingsMenu::QuickChangeBalancedSetting() {
	hudOpacity = 0.85;
	currentCrosshair = Full;
	crosshairDropDown.QuickOverrideLabel("Full");
	compassEnabled = true;
	notificationsEnabled = true;
}
void MISSINGUISettingsMenu::QuickChangeGameSetting() {
	hudOpacity = 1.0;
	currentCrosshair = Simple; 
	crosshairDropDown.QuickOverrideLabel("Simple");
	compassEnabled = true;
	notificationsEnabled = true;
}
void MISSINGUISettingsMenu::QuickChangeCinematicSetting() {
	hudOpacity = 0.0;
	currentCrosshair = Simple;
	crosshairDropDown.QuickOverrideLabel("Simple");
	compassEnabled = false;
	notificationsEnabled = false;
}
#pragma endregion