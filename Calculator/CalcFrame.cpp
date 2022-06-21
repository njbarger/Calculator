#include "CalcFrame.h"
#include "ButtonFactory.h"
#include "CalcProcessor.h"
#include <iostream>

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
	//button_parenth = buttonFactory.CreateParenthButton(this);
	button_decimalPoint = buttonFactory.CreateDecimalPointButton(this);

	// Dec/Bin/Hex
	button_dec = buttonFactory.CreateDecButton(this);
	button_bin = buttonFactory.CreateBinButton(this);
	button_hex = buttonFactory.CreateHexButton(this);

	// Clear / Clear-Entry
	button_clearEntry = buttonFactory.CreateClearEntryButton(this);
	button_clear = buttonFactory.CreateClearButton(this);

	// Text-box for Value
	textbox_value = new wxTextCtrl(this, 23, "0", wxPoint(10, 10), wxSize(475, 125), (long)wxTE_RIGHT);

	// Bind any button press to OnButtonClicked, where button id is checked
	Bind(wxEVT_BUTTON, &CalcFrame::OnButtonClicked, this);
}
CalcFrame::~CalcFrame()
{

}

void CalcFrame::OnButtonClicked(wxCommandEvent& evt)
{
	textbox_value->Clear();
	//CalcProcessor* processor = CalcProcessor::GetInstance();
	IBaseCommand* command = CalcProcessor::GetInstance();
	int id = evt.GetId();
	if (calculated && id < 10)
	{
		command->Clear();
		calculated = false;

	}

	if (command->CheckForOnlyZero()) {
		textbox_value->Clear();
		command->SetStrVal("");

	}
	// Numbers
	if (id < 10)
	{
		// Add number to currValue AddToValue(id);
		command->AddNumberToStrVal(std::to_string(id));
		(*textbox_value) << command->GetStrVal();
	}

	// Negation
	else if (id == 10)
	{
		// Negation logic, will need to check textbox_value for int value
		command->CheckForOnlyZero();
		command->CheckForRecentOperand();
		command->SetStrVal(command->MakeNegative());
		(*textbox_value) << command->GetStrVal();
	}

	// operators
	else if (id >= 11 && id <= 17)
	{
		calculated = false;
		float floatCompare;
		command->CheckForOnlyZero();

		switch (id)
		{
		default:
			break;

			// =
		case 11:
			command->CheckForRecentOperand();
			floatCompare = command->Execute();
			if (floatCompare == (int)floatCompare) {
				command->SetStrVal(std::to_string((int)floatCompare));
			}
			else
			{
				command->SetStrVal(std::to_string(floatCompare));
			}
			calculated = true;
			break;

			// +
		case 12:
			command->AddCharToStrVal('+');
			break;

			// -
		case 13:
			command->AddCharToStrVal('-');
			break;

			// *
		case 14:
			command->AddCharToStrVal('*');
			break;

			// /
		case 15:
			command->AddCharToStrVal('/');
			break;

			// %
		case 16:
			command->AddCharToStrVal('%');
			break;

			// ( )
		case 17:
			if (command->CheckForOnlyZero()) {
				command->SetStrVal("");
			}
			if (openParenth)
			{
				command->AddCharToStrVal('(');
				openParenth = false;
			}
			else
			{
				command->AddCharToStrVal(')');
				openParenth = true;
			}
			break;
		}
		(*textbox_value) << command->GetStrVal();
	}

	// Bin/Dec/Hex
	else if (id >= 18 && id <= 20)
	{
		command->CheckForOnlyZero();
		command->CheckForRecentOperand();
		textbox_value->Clear();
		float decVal = command->GetDec();
		switch (id)
		{
		default:
			break;
		case 18:
			if (decVal == (int)decVal) {
				(*textbox_value) << (int)decVal;
			}
			else {
				(*textbox_value) << decVal;
			}
			break;
		case 19:
			(*textbox_value) << command->GetBin();
			break;
		case 20:
			(*textbox_value) << command->GetHex();
			break;

		}
	}

	// Clear Entry
	else if (id == 21)
	{
		// Keep recorded values first
		command->ClearEntry();

		// update textbox
		(*textbox_value) << command->GetStrVal();
	}

	// Clear
	else if (id == 22)
	{
		// Clear recorded values
		command->Clear();

		// Clear textbox
		(*textbox_value) << command->GetStrVal();
	}

	// Decimal Point
	else if (id == 23)
	{
		command->AddCharToStrVal('.');
		(*textbox_value) << command->GetStrVal();
	}
}

