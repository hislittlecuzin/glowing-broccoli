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

#pragma endregion

class MISSINGGameSettingsMenu { 
public:
	MISSINGGameSettingsMenu() {
		
		//Cannot iterate over an enumeration like you can in C#.
		//Enumerations in C++ don't store the text of the value, only the value.
		//Could have used a data structure, but there's no points since this is the only time I set it. 
		difficultyDropDown.SetSpecificButtonID(Easy, "Easy", "For new players");
		difficultyDropDown.SetSpecificButtonID(Medium, "Medium", "Recommended difficulty");
		difficultyDropDown.SetSpecificButtonID(Hard, "Hard", "For the best players");

		basicControlMethodDropDown.SetSpecificButtonID(Keyboard, "Keyboard", "Keyboard and mouse");
		basicControlMethodDropDown.SetSpecificButtonID(Controller1, "Controller", "Standard game console controller");

		controllerAimAssistDropDown.SetSpecificButtonID(None, "None", "No aim assist");
		controllerAimAssistDropDown.SetSpecificButtonID(Some, "Some", "Just a little aim assist");
		controllerAimAssistDropDown.SetSpecificButtonID(Maximum, "Maximum", "A lot of aim assist. Good for new players");
	};

	void DisplayMenu();
	
#pragma region Code_Set_Settings
	int CodeGetCommonSettings() {
		return currentDifficulty;
	}
	void CodeSetCommonSettings(int arg) {
		if (arg >= Easy && arg < DIFFICULTYoPTIONScOUNT) {
			currentDifficulty = arg;
		}
		else {
			//currentDifficulty = Medium;
		}
	}

#pragma endregion

	void QuickChangeBalancedSetting();
	void QuickChangeGameSetting();
	void QuickChangeCinematicSetting();

private:
	
	void DisplayTips();
	void DisplayMainGameOptions();
	void DisplayControls();


#pragma region Tips_Variables
	idUTILITYTitle tipsRelatedSettingsTitle = idUTILITYTitle("Hint Settings:");

	bool tutorialsEnabled					= true;
	idUTILITYCheckBox tutorialsCheckBox = idUTILITYCheckBox("Show Tutorials:");

	//Change to enum?
	// 1. Idiot(Always have something on screen to guide me. "I'm probably not even paying attention." 
			//also good if you haven't played the game in a while & forgot how to play.)
	// 2. Essential (Seldom Guide me) Sometimes if you can't figure out where to go, we'll show you. Some things you likely don't know will pop up.
	// 3. NoTips (Never guide me) You hate tutorials & don't care at all what I have to say. 
	bool inGameTipsEnabled					= true;
	idUTILITYCheckBox inGameTipsCheckBox = idUTILITYCheckBox("Show In Game Tips:");
#pragma endregion

#pragma region Main_game_options_Variables
	idUTILITYTitle mainGameRelatedSettingsTitle = idUTILITYTitle("Main Gameplay Settings:");

	enum DifficultOptions {
		Easy,
		Medium,
		Hard,
		DIFFICULTYoPTIONScOUNT
	};
	int currentDifficulty					= Easy;
	idUTILITYDropDownMenu difficultyDropDown = idUTILITYDropDownMenu(DIFFICULTYoPTIONScOUNT, "Difficulty:", "Easy");

	bool autoSwitchWeaponsOnEmptyEnabled	= true;
	idUTILITYCheckBox autoSwitchWeaponsOnEmptyCheckBox = idUTILITYCheckBox("Auto-Switch Weapons When Out Of Ammo:");

	bool autoSwitchWeaponsOnNewEnabled		= true;
	idUTILITYCheckBox autoSwitchWeaponsOnNewCheckBox = idUTILITYCheckBox("Auto-Switch To New Weapon When Picked Up:");

	bool screenShakeEnabled					= true;
	idUTILITYCheckBox screenShakeCheckBox = idUTILITYCheckBox("Screen Shake:");
#pragma endregion

#pragma region Controls_Variables
	idUTILITYTitle controlRelatedSettingsTitle = idUTILITYTitle("Control Settings:");

	//General Settings
	//What if there's more than 1 controller hooked up to the console?
	//Sometimes consoles refuse to allow a controller to take player 1 even if the player 1 controller is broken. 
	//Anecdote: One time, even after a hard console power off, the first controller that turned on selected player 2. 
	enum InputMethod {
		Keyboard,
		Controller1,
		Controller2,
		Controller3,
		Controller4,
		INPUTmETHODcOUNT
	};
	int currentControlMethod				= Keyboard;
	idUTILITYDropDownMenu basicControlMethodDropDown = idUTILITYDropDownMenu(2, "Input:", "Keyboard");
	//NUMBER IN CODE?! Yes. Keyboards and Controllers are the only 2 ever expected. 
	//The only numbers I ever put in code are -1, 0, 1, & 2. Otherwise, I find a way to use a variable.
	idUTILITYDropDownMenu advancedControlMethodDropDown = idUTILITYDropDownMenu(INPUTmETHODcOUNT, "Input:", "Keyboard");

	
#pragma region KeyboardSettings
	
	idUTILITYTitle keyboardRelatedSettingsTitle = idUTILITYTitle("Keyboard Settings:");

	//X & Y used to be separate, but I figured there was enough range that it didn't matter. 
	//No mouse smoothing because I never heard of anyone that explicitely turns it on for gaming. 
	float minMouseSensitivity				= 10.0f;
	float maxMouseSensitivity				= 100.0f;
	float mouseHorizontalSensitivity		= 50.0f;
	idUTILITYSlider mouseHorizontalSensitivitySlider = idUTILITYSlider("Mouse X Sensitivity:");
	float mouseVerticalSensitivity			= 50.0f;
	idUTILITYSlider mouseVerticalSensitivitySlider = idUTILITYSlider("Mouse Y Sensitivity:");

	bool invertKeyboardLookEnabled			= false;
	idUTILITYCheckBox invertKeyboardLookCheckBox = idUTILITYCheckBox("Invert Mouse Look:");
#pragma endregion

#pragma region Controller Settings

	idUTILITYTitle controllerRelatedSettingsTitle = idUTILITYTitle("Controller Settings:");

	bool invertControllerLookEnabled		= false;
	idUTILITYCheckBox invertControllerLookCheckBox = idUTILITYCheckBox("Invert Controller Look:");

	bool controllerVibrationEnabled			= true;
	idUTILITYCheckBox controllerVibrationCheckBox = idUTILITYCheckBox("Controller Vibration:");

	enum ControllerAimAssistMethods {
		None,
		Some,
		Maximum,
		CONTROLLERaIMaSSISTmETHODScOUNT
	};
	int currentControllerAimAssist			= Maximum;
	idUTILITYDropDownMenu controllerAimAssistDropDown = idUTILITYDropDownMenu(CONTROLLERaIMaSSISTmETHODScOUNT, "Controller Aim Assist Level:", "Maximum");

	//Separate controller sensitivity ranges as joysticks are less precise than mice due to size.
	//I remember some console games that adjust sensitivity do hard integers from 1 to 10. Should have created an integer slider Utility. Hindsight is 2020.
	float minControllerSensitivity			= 10.0f;
	float maxControllerSensitivity			= 100.0f;
	float controllerHorizontalSensitivity	= 50.0f;
	idUTILITYSlider controllerHorizontalSensitivitySlider = idUTILITYSlider("Controller X Sensitivity:");
	float controllerVerticalSensitivity		= 50.0f;
	idUTILITYSlider controllerVerticalSensitivitySlider = idUTILITYSlider("Controller Y Sensitivity:");
#pragma endregion
	
#pragma endregion
};