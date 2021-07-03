/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma once

#include "../MISSING_Interview_lib/MISSING_Interview_lib.h"

class MISSINGUTILITYASCIIArt {
public:
	MISSINGUTILITYASCIIArt(char* newText) {
		text = newText;
	};

	void ShowASCIIArt(int indent) {
		ImGui::SetCursorPosX(indent);
		ImGui::Text(text);
	};

private:
	char* text;

};