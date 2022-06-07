#include "CalcFrame.h"
#include <iostream>


CalcFrame::CalcFrame() : wxFrame(nullptr, wxID_ANY, "Baby's First Calculator", wxPoint(750, 150), wxSize(510, 610))
{
	// Initialize all buttons
	// Nums
	button_num0 = new wxButton(this, wxID_ANY, "0", wxPoint(250, 475), wxSize(75, 75));
	button_num1 = new wxButton(this, wxID_ANY, "1", wxPoint(170, 395), wxSize(75, 75));
	button_num2 = new wxButton(this, wxID_ANY, "2", wxPoint(250, 395), wxSize(75, 75));
	button_num3 = new wxButton(this, wxID_ANY, "3", wxPoint(330, 395), wxSize(75, 75));
	button_num4 = new wxButton(this, wxID_ANY, "4", wxPoint(170, 315), wxSize(75, 75));
	button_num5 = new wxButton(this, wxID_ANY, "5", wxPoint(250, 315), wxSize(75, 75));
	button_num6 = new wxButton(this, wxID_ANY, "6", wxPoint(330, 315), wxSize(75, 75));
	button_num7 = new wxButton(this, wxID_ANY, "7", wxPoint(170, 235), wxSize(75, 75));
	button_num8 = new wxButton(this, wxID_ANY, "8", wxPoint(250, 235), wxSize(75, 75));
	button_num9 = new wxButton(this, wxID_ANY, "9", wxPoint(330, 235), wxSize(75, 75));

	// Operators
	button_add = new wxButton(this, wxID_ANY, "+", wxPoint(410, 315), wxSize(75, 75));
	button_sub = new wxButton(this, wxID_ANY, "-", wxPoint(410, 235), wxSize(75, 75));
	button_mult = new wxButton(this, wxID_ANY, "*", wxPoint(410, 155), wxSize(75, 75));
	button_div = new wxButton(this, wxID_ANY, "/", wxPoint(330, 155), wxSize(75, 75));
	button_mod = new wxButton(this, wxID_ANY, "%", wxPoint(250, 155), wxSize(75, 75));
	button_equals = new wxButton(this, wxID_ANY, "=", wxPoint(410, 395), wxSize(75, 155));
	button_parenth = new wxButton(this, wxID_ANY, "( )", wxPoint(170, 155), wxSize(75, 75));


	// Negation
	button_negative = new wxButton(this, wxID_ANY, "-(x)", wxPoint(330, 475), wxSize(75, 75));

	// Clear / Clear-Entry
	button_clear = new wxButton(this, wxID_ANY, "Clear", wxPoint(10, 475), wxSize(235, 75));
	button_clearEntry = new wxButton(this, wxID_ANY, "CE", wxPoint(10, 395), wxSize(150, 75));

	// Dec/Bin/Hex
	button_dec = new wxButton(this, wxID_ANY, "Dec", wxPoint(10, 155), wxSize(150, 75));
	button_bin = new wxButton(this, wxID_ANY, "Bin", wxPoint(10, 235), wxSize(150, 75));
	button_hex = new wxButton(this, wxID_ANY, "Hex", wxPoint(10, 315), wxSize(150, 75));

	// Text-box for Value
	textbox_value = new wxTextCtrl(this, wxID_ANY, " Value goes here ", wxPoint(10, 10), wxSize(475, 125));
	// redirect to std::cout		// redirects until end of scopew
	/*wxStreamToTextRedirector redirect(textbox_value);
	textbox_value->Clear();
	std::cout << "\nTextbox changed correctly..." << std::endl;*/
}
CalcFrame::~CalcFrame()
{

}