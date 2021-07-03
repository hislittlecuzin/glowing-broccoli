/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/

#pragma region Includes

#include "Main_Menu.h"
#include "MISSING_Interview_lib/MISSING_Interview_Lib.h"
#include <iostream>
#pragma endregion

MISSINGMainMenu localMainMenu;
MISSINGMainMenu * g_MainMenu = &localMainMenu;

/*
================================================
AlecMainMenu::DisplayMenu
================================================
*/

void MISSINGMainMenu::DisplayMenu() {

#pragma region IMGUI_Setup
	ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_Always);

	if (!ImGui::Begin("Main_Menu", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}
#pragma endregion

	DisplayGraphics();
	DisplayButtons();


	ImGui::End();
}

#pragma region Displays
void MISSINGMainMenu::DisplayGraphics() {

	ImGui::Text("MAIN MENU!");
	ImGui::Spacing();
	ImGui::Spacing();

	line1 .ShowASCIIArt(imageIndent);
	line2 .ShowASCIIArt(imageIndent);
	line3 .ShowASCIIArt(imageIndent);
	line4 .ShowASCIIArt(imageIndent);
	line5 .ShowASCIIArt(imageIndent);
	line6 .ShowASCIIArt(imageIndent);
	line7 .ShowASCIIArt(imageIndent);
	line8 .ShowASCIIArt(imageIndent);
	line9 .ShowASCIIArt(imageIndent);
	line10.ShowASCIIArt(imageIndent);
	line11.ShowASCIIArt(imageIndent);
	line12.ShowASCIIArt(imageIndent);
	line13.ShowASCIIArt(imageIndent);
	line14.ShowASCIIArt(imageIndent);
	line15.ShowASCIIArt(imageIndent);
	line16.ShowASCIIArt(imageIndent);
	line17.ShowASCIIArt(imageIndent);
	line18.ShowASCIIArt(imageIndent);
	line19.ShowASCIIArt(imageIndent);

	ImGui::SetCursorPosX(rightOfScreen);
	ImGui::SetCursorPosY(bottomOfScreen);
	ImGui::Text("*Not actually Doom");
}
void MISSINGMainMenu::DisplayButtons() {
	
	if (GetValueOfButton("Play", playButtonXOffset, playButtonYOffset)) {
		PlayDeniedSound();
	}
	
	goToSettings = GetValueOfButton("Settings", settingsButtonXOffset, settingsButtonYOffset);
	shouldQuit = GetValueOfButton("Quit", quitButtonXOffset, quitButtonYOffset);
}

void MISSINGMainMenu::PlayDeniedSound() {
	Beep(350, 500);//"Nuh uh"
	Beep(325, 250);//Sad... delay between notes-at least in debug.
}
bool MISSINGMainMenu::GetValueOfButton(const char* buttonName, int xOffset, int yOffset) {
	ImGui::SetCursorPosX(middleOfScreen + xOffset);
	ImGui::SetCursorPosY(bottomThirdOfScreen + yOffset);
	if (ImGui::Button(buttonName)) {
		return true;
	}
	return false;
}

#pragma endregion
