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

class MISSINGVideoSettingsMenu {
public:
	MISSINGVideoSettingsMenu() {
		videoModeDropDown.SetSpecificButtonID(Fullscreen, "Fullscreen", "Fullscreen mode that takes over the monitor");
		videoModeDropDown.SetSpecificButtonID(Windowed, "Windowed", "Windowed with the border like most normal programs");
		videoModeDropDown.SetSpecificButtonID(WindowedFullscreen, "WindowedFullscreen", "Similar to windowed but without the borders");

		aspectRatioDropDown.SetSpecificButtonID(SixteenByNine, "16:9", "Standard HD widescreen resolution");
		aspectRatioDropDown.SetSpecificButtonID(FourByThree, "4:3", "Standard fullscreen resolution");

		sixteenByNineResolutionDropDown.SetSpecificButtonID(TenEightyP16x9, "1920 x 1080", "Full HD");
		sixteenByNineResolutionDropDown.SetSpecificButtonID(SevenTwentyP16x9, "1280 x 720", "HD");

		fourByThreeResolutionDropDown.SetSpecificButtonID(FourEightyP4x3, "640 x 480", "Very easy to run");
		fourByThreeResolutionDropDown.SetSpecificButtonID(SixHundredP4x3, "800 x 600", "Easy to run, but with a little extra detail");

		shadowQualityDropDown.SetSpecificButtonID(Low, "Low", "Best performance");
		shadowQualityDropDown.SetSpecificButtonID(Medium, "Medium", "Best balance between performance & quality");
		shadowQualityDropDown.SetSpecificButtonID(High, "High", "Highest quality for the best picture");
	};

	void DisplayMenu();

#pragma region Code_Set_Settings
	float CodeGetCommonSettings() {
		return fOV;
	}

	void CodeSetCommonSettings(float arg) {
		if (arg >= minFOV && arg <= maxFOV) {
			fOV = arg;
		}
		else {

		}
	}
#pragma endregion

	void QuickChangeBalancedSetting();
	void QuickChangeGameSetting();
	void QuickChangeCinematicSetting();

private:

	void DisplayModes();
	void DisplayResolutions();
	void DisplayPreferences();
	void DisplayQualitys(); //This is incorrect English, but consistent with code. Better to be consistently wrong than inconsistently correct.

#pragma region Modes_Variables
	//Good thing we don't have to code for VGA, HDMI, and so fourth individually anymore. 
	idUTILITYTitle modeTitle = idUTILITYTitle("Video Mode:");

	enum VideoMode {
		Fullscreen,
		Windowed,
		WindowedFullscreen,
		VIDEOmODEcOUNT
	};
	int currentVideoMode				= Fullscreen;
	idUTILITYDropDownMenu videoModeDropDown = idUTILITYDropDownMenu(VIDEOmODEcOUNT, "Video Mode:", "Fullscreen");
#pragma endregion

#pragma region Resolution_Variables
	//Stuff related to resolutions. In the new Doom games you list all the resolutions with their Aspect Ratios.
	//I could do that but I thought I'd go with a theme of contextual settings. Only see stuff you're going to be working with.
	//One oversight could be if you forget what aspect ratio your monitor is, then you may not find your resolution.
	//I'm going to guess the game will autodetect recommended settings & then if you're going into them, you have a low end system
	//or know what things are already. 
	idUTILITYTitle resolutionTitle = idUTILITYTitle("Resolution:");

	enum AspectRatio {
		SixteenByNine,
		FourByThree,
		ASPECTrATIOcOUNT
	};
	int currentAspectRatio				= SixteenByNine;
	idUTILITYDropDownMenu aspectRatioDropDown = idUTILITYDropDownMenu(ASPECTrATIOcOUNT, "Aspect Ratio:", "16:9");

	enum SixteenByNineResolutions {
		TenEightyP16x9,
		SevenTwentyP16x9,
		SIXTEENbYnINErESOLUTIONScOUNT
	};
	int currentSixteenByNineResolution	= TenEightyP16x9;
	idUTILITYDropDownMenu sixteenByNineResolutionDropDown = idUTILITYDropDownMenu(SIXTEENbYnINErESOLUTIONScOUNT, "Resolution:", "1920 x 1080");

	enum FourByThreeResolutions {
		FourEightyP4x3,
		SixHundredP4x3,
		FOURbYtHREErESOLUTIONScOUNT
	};
	int currentFourByThreeResolutions	= FourEightyP4x3;
	idUTILITYDropDownMenu fourByThreeResolutionDropDown = idUTILITYDropDownMenu(FOURbYtHREErESOLUTIONScOUNT, "Resolution:", "640 x 480");
#pragma endregion

#pragma region Preferences_Variables
	//Kinda like gameplay settings.
	//Guess it was self documenting code.

	idUTILITYTitle preferencesTitle = idUTILITYTitle("Video Preferences:");

	float minFOV						= 90.0f;
	float maxFOV						= 120.0f;
	float fOV							= 100.0f;
	idUTILITYSlider fOVSlider = idUTILITYSlider("FOV:  ");
	

	bool motionBlurEnabled				= false;
	idUTILITYCheckBox motionBlurCheckBox = idUTILITYCheckBox("Motion Blur:");

	float minGamma						= -1.0f;
	float maxGamma						= 1.0f;
	float gamma							= 1.0f;
	idUTILITYSlider gammaSlider = idUTILITYSlider("Gamma:");

#pragma endregion

#pragma region Quality_Variables
	//We could put like model quality & texture resolution here too. 
	//Texture resolution would be game quality even though it has resolution in the name. At least in my opinion.

	idUTILITYTitle qualityTitle = idUTILITYTitle("Game Quality:");

	enum ShadowQuality {
		Low,
		Medium,
		High,
		SHADOWqUALITYcOUNT
	};
	int currentShadowQuality			= Medium;
	idUTILITYDropDownMenu shadowQualityDropDown = idUTILITYDropDownMenu(SHADOWqUALITYcOUNT, "Shadow Quality:", "Medium");
#pragma endregion

};