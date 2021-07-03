#pragma once

class MISSINGUTILITYSettingsFormatter {
public:

	static int GetCheckBoxXOffset() {
		return checkBoxXOffset;
	};
	static int GetDropDownXOffset() {
		return dropdownXOffset;
	};
	static int GetSliderPrecisionXOffset() {
		return sliderPrecisionXOffset;
	};


	static int GetSubMenuTitleXOffset() {
		return subMenuTitleXOffset;
	};
	static int GetSubMenuBarXOffset() {
		return subMenuBarXOffset;
	};

private:

	//There is no text scaling confirmed in some forum posts. 
	//No need to dynamically calculate. These look good for the resolution.

	//About 90% 
	static const int checkBoxXOffset = 1100;
	static const int dropdownXOffset = 1100;
	static const int sliderPrecisionXOffset = 1100;

	//about 50%
	static const int subMenuTitleXOffset = 520;
	//about 25% 
	static const int subMenuBarXOffset = 300;
	


};

