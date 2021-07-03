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

class MISSINGUISettingsMenu {
public:
	MISSINGUISettingsMenu() {
		crosshairDropDown.SetSpecificButtonID(Full, "Full", "Full crosshair with all the detail");
		crosshairDropDown.SetSpecificButtonID(Simple, "Simple", "Simple crosshair with almost nothing on it");
	};

	void DisplayMenu();

#pragma region Code_Set_Settings
	bool CodeGetCommonSettings() {
		return compassEnabled;
	}

	void CodeSetCommonSettings(int arg) {
		if (arg == 1) {
			compassEnabled = true;
		}
		else if (arg == 0) {
			compassEnabled = false;
		}
		else {
			//compassEnabled = true;
		}
	}

#pragma endregion

	void QuickChangeBalancedSetting();
	void QuickChangeGameSetting();
	void QuickChangeCinematicSetting();

private:

	void DisplayOpacitys();
	void DisplayToggles();


#pragma region Opacity_Variables

	idUTILITYTitle opacityRelatedSettingsTitle = idUTILITYTitle("Opacity:");

	float minOpacity			= 0.0f;
	float maxOpacity			= 1.0f;
	float hudOpacity			= 1.0f;
	idUTILITYSlider hudOpacitySlider = idUTILITYSlider("HUD Opacity");
		
#pragma endregion


#pragma region Toggle_Variables
	
	idUTILITYTitle toggleRelatedSettingsTitle = idUTILITYTitle("Toggle Settings:");

	enum CrossHairStyle {
		Full,
		Simple,
		CROSShAIRsTYLEcOUNT
	};
	int currentCrosshair		= Full;
	idUTILITYDropDownMenu crosshairDropDown = idUTILITYDropDownMenu(CROSShAIRsTYLEcOUNT, "Crosshair Style:", "Full");

	bool compassEnabled			= true;
	idUTILITYCheckBox compassEnabledCheckBox = idUTILITYCheckBox("Enable Compass:");

	bool notificationsEnabled	= true;
	idUTILITYCheckBox notificationsCheckBox = idUTILITYCheckBox("Enable Notifications:");

#pragma endregion

};