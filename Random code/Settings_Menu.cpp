/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma region Includes

#include "Settings_Menu.h"
#include "MISSING_Interview_lib/MISSING_Interview_lib.h"
#include "Menu_Utilities/SettingsFormatter.h"
#pragma endregion

MISSINGSettingsMenu localSettingMenu;
MISSINGSettingsMenu * g_SettingsMenu = &localSettingMenu;



/*
================================================
MISSINGSettingsMenu::DisplayMenu
================================================
*/
void MISSINGSettingsMenu::DisplayMenu() {
	
#pragma region IMGUI_Setup
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_Always);

	if (!ImGui::Begin("Settings_Menu", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}
#pragma endregion

	SettingMenuHeader();
	
	DisplaySubMenuSelected();
	
	DisplayMainMenuButton();

	ImGui::End();
}

void MISSINGSettingsMenu::SettingMenuHeader() {
	ImGui::Text("SETTINGS MENU!");
	ImGui::Spacing();
	ImGui::Spacing();


	//Subtitle to show which menu we are on. 
	ImGui::PushStyleColor(ImGuiCol_Text, titleColor);
	ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetSubMenuTitleXOffset());
	switch (currentSettingsMenu)
	{
	case settingQuick:
		ImGui::Text("Quick Settings:");
		break;
	case settingGame:
		ImGui::Text("Game Settings:");
		break;
	case settingUI:
		ImGui::Text("UI Settings:");
		break;
	case settingVideo:
		ImGui::Text("Video Settings:");
		break;
	case settingAudio:
		ImGui::Text("Audio Settings:");
		break;
	default:
		ImGui::Text("Select a Settings Menu:");
		break;
	}
	ImGui::PopStyleColor(pushedColors);


#pragma region Buttons_to_select_sub_menus
	//No time to check if any settings were changed with the time remaining. 
	//Workaround is to just set to custom if they look at any menus other than Quick Settings.
	ImGui::SetCursorPosX(MISSINGUTILITYSettingsFormatter::GetSubMenuBarXOffset());
	if (ImGui::Button("Quick Settings")) {
		currentSettingsMenu = settingQuick;
	}
	ImGui::SameLine();
	if (ImGui::Button("Game Settings")) {
		quickSettings.SetToCustomMode();
		currentSettingsMenu = settingGame;
	}
	ImGui::SameLine();
	if (ImGui::Button("UI Settings")) {
		quickSettings.SetToCustomMode();
		currentSettingsMenu = settingUI;
	}
	ImGui::SameLine();
	if (ImGui::Button("Video Settings")) {
		quickSettings.SetToCustomMode();
		currentSettingsMenu = settingVideo;
	}
	ImGui::SameLine();
	if (ImGui::Button("Audio Settings")) {
		quickSettings.SetToCustomMode();
		currentSettingsMenu = settingAudio;
	}
#pragma endregion

}
#pragma region Displays
void MISSINGSettingsMenu::DisplaySubMenuSelected() {


	switch (currentSettingsMenu)
	{
	case settingGame:
		gameSettings.DisplayMenu();
		break;
	case settingUI:
		uiSettings.DisplayMenu();
		break;
	case settingVideo:
		videoSettings.DisplayMenu();
		break;
	case settingAudio:
		audioSettings.DisplayMenu();
		break;
	case settingQuick:
		quickSettings.DisplayMenu();
		break;
	default:
		ImGui::Text("Select a Settings Menu.");
		break;
	}


}
void MISSINGSettingsMenu::DisplayMainMenuButton() {
	ImGui::SetCursorPosX(0);
	ImGui::SetCursorPosY(bottomOfScreen);
	if (ImGui::Button("Main Menu")) {
		goToMainMenu = true;
	}
}
#pragma endregion
