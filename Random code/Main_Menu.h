/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#ifndef __MAIN_MENU_H_
#define __MAIN_MENU_H_

#include "Menu_Utilities/ASCII_Art_Menu_Utility.h"

class MISSINGMainMenu {

public:
	MISSINGMainMenu() {
	}

	void		DisplayMenu();

	bool GoToSettings() {
		if (goToSettings) {
			goToSettings = false;
			return true;
		}
		return false;
	};
	bool ShouldQuit() {
		return shouldQuit;
	};

private:

	void DisplayGraphics();
	void DisplayButtons();

	void PlayDeniedSound();
	bool GetValueOfButton(const char* buttonName, int xOffset, int yOffset);

	bool goToSettings		= false;
	bool shouldQuit			= false;

#pragma region UI_Alignment_Variables

	int rightOfScreen		= 1125;
	int bottomOfScreen		= 700;
	int middleOfScreen		= 600;
	int bottomThirdOfScreen	= 432;
	int playButtonXOffset	= 0;
	int settingsButtonXOffset = -13;
	int quitButtonXOffset = 0;
	int playButtonYOffset	= 0;
	int settingsButtonYOffset = 60;
	int quitButtonYOffset = 120;

	//1280 / 4 = 320. We only have 1 target resolution.
	int imageIndent			= 320;

#pragma endregion

#pragma region ASCII_Art_Variables

	//Borrowed without permission from:
	//https://www.gamers.org/~fpv/doomlogo.html


	//Yes, this SHOULD be an array/datastructure.
	//It's unchanging, I'm running out of time & I had enough of null references for today.
	MISSINGUTILITYASCIIArt line1  =	MISSINGUTILITYASCIIArt("=================      ==============     ===============   ========  =========  *"			);
	MISSINGUTILITYASCIIArt line2  =	MISSINGUTILITYASCIIArt("\\\\ . . . . . . . \\\\   //. . . . . . .\\\\  //. . . . . . .\\\\   \\\\. . .\\\\// . . //"	);
	MISSINGUTILITYASCIIArt line3  =	MISSINGUTILITYASCIIArt("|| . .._____. . .||  ||. . ._____. . .|| ||. . ._____. . .|| || . . .\\/ . . .||"			);
	MISSINGUTILITYASCIIArt line4  =	MISSINGUTILITYASCIIArt("|| . .||   ||. . ||  || . .||   ||. . || || . .||   ||. . || ||. . . . . . . ||"				);
	MISSINGUTILITYASCIIArt line5  =	MISSINGUTILITYASCIIArt("||. . ||   || . .||  ||. . ||   || . .|| ||. . ||   || . .|| || . | . . . . .||"				);
	MISSINGUTILITYASCIIArt line6  =	MISSINGUTILITYASCIIArt("|| . .||   ||._ -||  ||-_ .||   ||. . || || . .||   ||._ -|| ||-_.|\\ . . . . ||"			);
	MISSINGUTILITYASCIIArt line7  =	MISSINGUTILITYASCIIArt("||. . ||   ||-'  ||  ||  `-||   || . .|| ||. . ||   ||-'  || ||  `|\\_ . .|. .||"			);
	MISSINGUTILITYASCIIArt line8  =	MISSINGUTILITYASCIIArt("||  ._||   ||    ||  ||    ||   ||_ . || || . _||   ||    || ||   |\\ `-_/| . ||"			);
	MISSINGUTILITYASCIIArt line9  =	MISSINGUTILITYASCIIArt("||_-' ||  .|/    ||  ||    \\|.  || `-_|| ||_-' || . |/    || ||   | \\  / |-_.||"			);
	MISSINGUTILITYASCIIArt line10 =	MISSINGUTILITYASCIIArt("||    ||_-'      ||  ||      `-_||    || ||    ||_-'      || ||   | \\  / |  `||"			);
	MISSINGUTILITYASCIIArt line11 =	MISSINGUTILITYASCIIArt("||    `'         ||  ||         `'    || ||    `'         || ||   | \\  / |   ||"			);
	MISSINGUTILITYASCIIArt line12 =	MISSINGUTILITYASCIIArt("||            .==='  `===.         .==='.`===.         .===' /==. |  \\/  |   ||"			);
	MISSINGUTILITYASCIIArt line13 =	MISSINGUTILITYASCIIArt("||         .=='   \\_|-_  `===. .==='  _|_   `===. .===' _-|_/   `==  \\/  |   ||"			);
	MISSINGUTILITYASCIIArt line14 =	MISSINGUTILITYASCIIArt("||      .=='    _-'    `-_   `='   _-'   `-_    `='  _-'    `-_  /|  \\/  |   ||"			);
	MISSINGUTILITYASCIIArt line15 =	MISSINGUTILITYASCIIArt("||   .=='    _-'          `-__\\._-'         `-_./__-'          `' |. /|  |   ||"			);
	MISSINGUTILITYASCIIArt line16 =	MISSINGUTILITYASCIIArt("||.=='    _-'                                                      `' |  /==.||"				);
	MISSINGUTILITYASCIIArt line17 =	MISSINGUTILITYASCIIArt("=='    _-'                                                             \\/   `=="			);
	MISSINGUTILITYASCIIArt line18 =	MISSINGUTILITYASCIIArt("\\   _-'                                                                 `-_   /"			);
	MISSINGUTILITYASCIIArt line19 =	MISSINGUTILITYASCIIArt(" `''                                                                       ``'"				);
#pragma endregion
};


extern MISSINGMainMenu * g_MainMenu;

#endif // !__MAIN_MENU_H_