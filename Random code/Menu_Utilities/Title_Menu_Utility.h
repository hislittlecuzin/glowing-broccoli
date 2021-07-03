/*
================================================================================================
CONFIDENTIAL AND PROPRIETARY INFORMATION/NOT FOR DISCLOSURE WITHOUT WRITTEN PERMISSION
Copyright 2021 Alec Fully Liable Not-Incorperate, a programmer dude. All Rights Requested.

Alec Fully Liable Not-Incorperate, a MISSSING company MISSING.
================================================================================================
*/
#pragma once

#pragma region Includes
#include <memory>
#include <string>
#include "../MISSING_Interview_lib/MISSING_Interview_lib.h"

#pragma endregion


class idUTILITYTitle {
public:
	idUTILITYTitle(const char* newLabel) {
		label = std::make_unique<const char*>(newLabel);
	};

	void ShowTitle() {
		ImGui::PushStyleColor(ImGuiCol_Text, titleColor);

		ImGui::Text(*label.get());
		ImGui::NextColumn();
		ImGui::Text(""); //Keep right column in alignment.
		ImGui::NextColumn();

		ImGui::PopStyleColor(pushedColors);
	}

private:
	std::unique_ptr<const char*> label;

	//Colors
	const ImVec4 titleColor = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
	const int pushedColors = 1;

};