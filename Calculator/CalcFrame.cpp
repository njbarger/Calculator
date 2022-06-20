#include "CalcFrame.h"
#include "ButtonFactory.h"
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
	button_parenth = buttonFactory.CreateParenthButton(this);

	// Dec/Bin/Hex
	button_dec = buttonFactory.CreateDecButton(this);
	button_bin = buttonFactory.CreateBinButton(this);
	button_hex = buttonFactory.CreateHexButton(this);

	// Clear / Clear-Entry
	button_clearEntry = buttonFactory.CreateClearEntryButton(this);
	button_clear = buttonFactory.CreateClearButton(this);

	// Text-box for Value
	textbox_value = new wxTextCtrl(this, 23, " ", wxPoint(10, 10), wxSize(475, 125), (long)wxTE_RIGHT);
	textbox_value->SetExtraStyle((long)wxHSCROLL);
	textbox_value->SetExtraStyle((long)wxTE_READONLY);

	// redirect to std::cout		// redirects until end of scopew
	//wxStreamToTextRedirector redirect(textbox_value);
	textbox_value->Clear();




	// Bind any button press to OnButtonClicked, where button id is checked
	Bind(wxEVT_BUTTON, &CalcFrame::OnButtonClicked, this);
}
CalcFrame::~CalcFrame()
{

}

void CalcFrame::OnButtonClicked(wxCommandEvent& evt)
{
	int id = evt.GetId();


	// Numbers
	if (id < 10)
	{
		(*textbox_value) << id;

		// Add number to currValue AddToValue(id);
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
			(*textbox_value) << '+';

			break;

			// -
		case 13:
			(*textbox_value) << '-';
			break;

			// *
		case 14:
			(*textbox_value) << '*';
			break;

			// /
		case 15:
			(*textbox_value) << '/';
			break;

			// %
		case 16:
			(*textbox_value) << '%';
			break;

			// ( )
		case 17:
			if (openParenth)
			{
				(*textbox_value) << '(';
				openParenth = false;
			}
			else
			{
				(*textbox_value) << ')';
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
			(*textbox_value) << "(Value was converted to decimal)";
			break;
		case 19:
			(*textbox_value) << "(Value was converted to binary)";
			break;
		case 20:
			(*textbox_value) << "(Value was converted to hexidecimal)";
			break;

		}
	}

	// Clear Entry
	else if (id == 21)
	{
		// Keep recorded values first


		// clear textbox
		textbox_value->Clear();
	}

	// Clear
	else if (id == 22)
	{
		// Clear recorded values


		// Clear textbox
		textbox_value->Clear();
	}
}

