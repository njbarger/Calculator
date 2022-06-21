#pragma once
#include "wx/wx.h"

class CalcFrame : public wxFrame
{
public:
	CalcFrame();
	~CalcFrame();

private:

	int screenWidth = 510;
	int screenHeight = 610;

	// bool for if textbox should clear or not
	bool doClear = true;
	// bool for if parenthesis start or finish
	bool openParenth = true;
	// bool for if enter was last pressed
	bool calculated = false;

	wxButton* buttonArray[10] = {};

	// Buttons for all numbers
	wxButton* button_num1 = nullptr;
	wxButton* button_num2 = nullptr;
	wxButton* button_num3 = nullptr;
	wxButton* button_num4 = nullptr;
	wxButton* button_num5 = nullptr;
	wxButton* button_num6 = nullptr;
	wxButton* button_num7 = nullptr;
	wxButton* button_num8 = nullptr;
	wxButton* button_num9 = nullptr;
	wxButton* button_num0 = nullptr;

	// Buttons for Operators
	wxButton* button_add = nullptr;
	wxButton* button_sub = nullptr;
	wxButton* button_mult = nullptr;
	wxButton* button_div = nullptr;
	wxButton* button_mod = nullptr;
	wxButton* button_equals = nullptr;
	wxButton* button_parenth = nullptr;

	// Button for negate
	wxButton* button_negative = nullptr;

	// Button for decimal point
	wxButton* button_decimalPoint = nullptr;

	// Buttons for Clear/Clear entry
	wxButton* button_clear = nullptr;
	wxButton* button_clearEntry = nullptr;

	// Buttons for Dec/Bin/Hex
	wxButton* button_dec = nullptr;
	wxButton* button_bin = nullptr;
	wxButton* button_hex = nullptr;

	// Text box for Value
	wxTextCtrl* textbox_value = nullptr;


	// Button Functions
	// numbers
	void OnButtonClicked(wxCommandEvent& evt);
};

