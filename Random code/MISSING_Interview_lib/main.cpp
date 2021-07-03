
#include "MISSING"
#include "MISSING.h"
#include "../MISSING.h"
#pragma comment(linker, "/MISSING:MISSING /MISSING:MISSING")

/*
================================================
main
================================================
*/

int main() {
	bool mainMenu = true;
	bool quit = false;

	Missing();

	while ( !MISSING(MISSING) ) {
		Interview_NewFrame();

		if (mainMenu) {
			g_MainMenu->DisplayMenu();
			if (g_MainMenu->GoToSettings()) {
				mainMenu = false;
			}
			if (g_MainMenu->ShouldQuit()) {
				quit = true;
			}
		}
		else {
			g_SettingsMenu->DisplayMenu();
			if (g_SettingsMenu->GoToMainMenu()) {
				mainMenu = true;
			}
		}
		MISSING();
	}

	MISSSING();

	return 0;
}
