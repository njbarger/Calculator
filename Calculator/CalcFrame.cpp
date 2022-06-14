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

	button_num0 = buttonFactory.CreateNumButton(this, 0, "0", wxPoint(250, 475), wxSize(75, 75));
	button_num1 = buttonFactory.CreateNumButton(this, 1, "1", wxPoint(170, 395), wxSize(75, 75));
	button_num2 = buttonFactory.CreateNumButton(this, 2, "2", wxPoint(250, 395), wxSize(75, 75));
	button_num3 = buttonFactory.CreateNumButton(this, 3, "3", wxPoint(330, 395), wxSize(75, 75));
	button_num4 = buttonFactory.CreateNumButton(this, 4, "4", wxPoint(170, 315), wxSize(75, 75));
	button_num5 = buttonFactory.CreateNumButton(this, 5, "5", wxPoint(250, 315), wxSize(75, 75));
	button_num6 = buttonFactory.CreateNumButton(this, 6, "6", wxPoint(330, 315), wxSize(75, 75));
	button_num7 = buttonFactory.CreateNumButton(this, 7, "7", wxPoint(170, 235), wxSize(75, 75));
	button_num8 = buttonFactory.CreateNumButton(this, 8, "8", wxPoint(250, 235), wxSize(75, 75));
	button_num9 = buttonFactory.CreateNumButton(this, 9, "9", wxPoint(330, 235), wxSize(75, 75));


	// Negation
	button_negative = buttonFactory.CreateNegativeButton(this, 10, "-(x)", wxPoint(330, 475), wxSize(75, 75));

	// Operators
	button_equals = buttonFactory.CreateEqualsButton(this, 11, "=", wxPoint(410, 395), wxSize(75, 155));
	button_add = buttonFactory.CreateAddButton(this, 12, "+", wxPoint(410, 315), wxSize(75, 75));
	button_sub = buttonFactory.CreateSubButton(this, 13, "-", wxPoint(410, 235), wxSize(75, 75));
	button_mult = buttonFactory.CreateMultButton(this, 14, "*", wxPoint(410, 155), wxSize(75, 75));
	button_div = buttonFactory.CreateDivButton(this, 15, "/", wxPoint(330, 155), wxSize(75, 75));
	button_mod = buttonFactory.CreateModuloButton(this, 16, "%", wxPoint(250, 155), wxSize(75, 75));
	button_parenth = buttonFactory.CreateParenthButton(this, 17, "( )", wxPoint(170, 155), wxSize(75, 75));

	// Dec/Bin/Hex
	button_dec = buttonFactory.CreateDecButton(this, 18, "Dec", wxPoint(10, 155), wxSize(150, 75));
	button_bin = buttonFactory.CreateBinButton(this, 19, "Bin", wxPoint(10, 235), wxSize(150, 75));
	button_hex = buttonFactory.CreateHexButton(this, 20, "Hex", wxPoint(10, 315), wxSize(150, 75));

	// Clear / Clear-Entry
	button_clearEntry = buttonFactory.CreateClearEntryButton(this, 21, "CE", wxPoint(10, 395), wxSize(150, 75));
	button_clear = buttonFactory.CreateClearButton(this, 22, "Clear", wxPoint(10, 475), wxSize(235, 75));

	// Text-box for Value
	textbox_value = new wxTextCtrl(this, 23, "Value goes here", wxPoint(10, 10), wxSize(475, 125), (long)wxTE_RIGHT);
	//textbox_value->SetExtraStyle((long)wxTE_DONTWRAP);
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
	else if (id >= 18 || id <= 20)
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

