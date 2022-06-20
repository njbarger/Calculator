#include "CalcFrame.h"
#include "ButtonFactory.h"
#include "CalcProcessor.h"
#include <iostream>
#

CalcFrame::CalcFrame() : wxFrame(nullptr, wxID_ANY, "Baby's First Calculator", wxPoint(750, 150), wxSize(510, 610))
{
	
	// Initialize screen settings
	this->SetSize(screenWidth, screenHeight);
	this->SetBackgroundColour(*wxWHITE);

	// Initialize all buttons
	// Nums

	ButtonFactory buttonFactory;

	// Numbers

	buttonFactory.CreateNumButtonArray(this, buttonArray);

	// Negation
	button_negative = buttonFactory.CreateNegativeButton(this);

	// Operators
	button_equals = buttonFactory.CreateEqualsButton(this);
	button_add = buttonFactory.CreateAddButton(this);
	button_sub = buttonFactory.CreateSubButton(this);
	button_mult = buttonFactory.CreateMultButton(this);
	button_div = buttonFactory.CreateDivButton(this);
	button_mod = buttonFactory.CreateModuloButton(this);
	button_parenth = buttonFactory.CreateParenthButton(this);

	// Dec/Bin/Hex
	button_dec = buttonFactory.CreateDecButton(this);
	button_bin = buttonFactory.CreateBinButton(this);
	button_hex = buttonFactory.CreateHexButton(this);

	// Clear / Clear-Entry
	button_clearEntry = buttonFactory.CreateClearEntryButton(this);
	button_clear = buttonFactory.CreateClearButton(this);

	// Text-box for Value
	textbox_value = new wxTextCtrl(this, 23, "0", wxPoint(10, 10), wxSize(475, 125), (long)wxTE_RIGHT);
	textbox_value->SetExtraStyle((long)wxHSCROLL);
	textbox_value->SetExtraStyle((long)wxTE_READONLY);

	// Bind any button press to OnButtonClicked, where button id is checked
	Bind(wxEVT_BUTTON, &CalcFrame::OnButtonClicked, this);
}
CalcFrame::~CalcFrame()
{

}

void CalcFrame::OnButtonClicked(wxCommandEvent& evt)
{
	textbox_value->Clear();
	CalcProcessor* processor = CalcProcessor::GetInstance();
	int id = evt.GetId();

	// Numbers
	if (id < 10)
	{
		// Add number to currValue AddToValue(id);
		processor->AddNumberToStringValue(std::to_string(id));
		(*textbox_value) << processor->GetStrVal();
	}

	// Negation
	else if (id == 10)
	{
		// Negation logic, will need to check textbox_value for int value
		(*textbox_value) << "(next entered value is now negative)  -";

		// MakeNegative(currValue) { 0 - (currValue) }
	}

	// operators
	else if (id >= 11 && id <= 17)
	{
		switch (id)
		{
		default:
			break;

			// =
		case 11:
			textbox_value->Clear();
			(*textbox_value) << '=' << " (Insert Answer Here) ";

			// Equals(currValue) { return math }

			break;

			// +
		case 12:
			//(*textbox_value) << '+';
			processor->SetNewValue();
			processor->AddCharToStringValue('+');
			(*textbox_value) << processor->GetStrVal();
			break;

			// -
		case 13:
			processor->SetNewValue();
			processor->AddCharToStringValue('-');
			(*textbox_value) << processor->GetStrVal();
			break;

			// *
		case 14:
			processor->SetNewValue();
			processor->AddCharToStringValue('*');
			(*textbox_value) << processor->GetStrVal();
			break;

			// /
		case 15:
			processor->SetNewValue();
			processor->AddCharToStringValue('/');
			(*textbox_value) << processor->GetStrVal();
			break;

			// %
		case 16:
			processor->SetNewValue();
			processor->AddCharToStringValue('%');
			(*textbox_value) << processor->GetStrVal();
			break;

			// ( )
		case 17:
			if (openParenth)
			{
				processor->SetNewValue();
				processor->AddCharToStringValue('(');
				(*textbox_value) << processor->GetStrVal();
				openParenth = false;
			}
			else
			{
				processor->SetNewValue();
				processor->AddCharToStringValue(')');
				(*textbox_value) << processor->GetStrVal();
				openParenth = true;
			}
			break;
		}
	}

	// Bin/Dec/Hex
	else if (id >= 18 && id <= 20)
	{
		textbox_value->Clear();
		switch (id)
		{
		default:
			break;
		case 18:
			(*textbox_value) << processor->GetDec();
			break;
		case 19:
			(*textbox_value) << processor->GetBin();
			break;
		case 20:
			(*textbox_value) << processor->GetHex();
			break;

		}
	}

	// Clear Entry
	else if (id == 21)
	{
		// Keep recorded values first
		processor->ClearEntry();

		// update textbox
		(*textbox_value) << processor->GetStrVal();
	}

	// Clear
	else if (id == 22)
	{
		// Clear recorded values
		processor->Clear();

		// Clear textbox
		(*textbox_value) << processor->GetStrVal();
	}
}

