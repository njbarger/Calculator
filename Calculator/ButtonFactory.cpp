#include "ButtonFactory.h"
#include "CalcFrame.h"
#include "CalcMain.h"

ButtonFactory::ButtonFactory()
{

}

ButtonFactory::~ButtonFactory()
{
}

void ButtonFactory::CheckEventId(int id)
{

}

wxButton* ButtonFactory::CreateNumButton(wxWindow* parent, int idNum, const char* label, wxPoint point)
{
	wxButton* temp = new wxButton(parent, idNum, label, point, wxSize(75, 75));
	return temp;
}

void ButtonFactory::CreateNumButtonArray(wxWindow* parent, wxButton** buttonArray)
{
	static const char* const numArr[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	int xCount = 0;
	int yCount = 0;
	for (int num = 0; num < 10; num++)
	{
		int x = 0;
		int y = 0;
		if (num == 0)
		{
			x = 250;
			y = 475;
			buttonArray[num] = CreateNumButton(parent, num, numArr[num], wxPoint(x, y));
		}
		else
		{
			switch (yCount)
			{
			default:
				break;
			case 0:
				y = 395;
				break;
			case 1:
				y = 315;
				break;
			case 2:
				y = 235;
				break;
			}

			switch (xCount)
			{
			default:
				break;
			case 0:
				x = 170;
				break;
			case 1:
				x = 250;
				break;
			case 2:
				x = 330;
				break;
			}

			buttonArray[num] = CreateNumButton(parent, num, numArr[num], wxPoint(x, y));
			if (xCount == 2)
			{
				xCount = 0;
				yCount++;
			}
			else
				xCount++;
		}

	}
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 12, "+", wxPoint(410, 315), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateSubButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 13, "-", wxPoint(410, 235), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateMultButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 14, "*", wxPoint(410, 155), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateDivButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 15, "/", wxPoint(330, 155), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 16, "%", wxPoint(250, 155), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 11, "=", wxPoint(410, 395), wxSize(75, 155));
	return temp;
}

wxButton* ButtonFactory::CreateParenthButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 17, "( )", wxPoint(170, 155), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 10, "-(x)", wxPoint(330, 475), wxSize(75, 75));
	return temp;
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 22, "Clear", wxPoint(10, 475), wxSize(235, 75));
	return temp;
}

wxButton* ButtonFactory::CreateClearEntryButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 21, "CE", wxPoint(10, 395), wxSize(150, 75));
	return temp;
}

wxButton* ButtonFactory::CreateDecButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 18, "Dec", wxPoint(10, 155), wxSize(150, 75));
	return temp;
}

wxButton* ButtonFactory::CreateBinButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 19, "Bin", wxPoint(10, 235), wxSize(150, 75));
	return temp;
}

wxButton* ButtonFactory::CreateHexButton(wxWindow* parent)
{
	wxButton* temp = new wxButton(parent, 20, "Hex", wxPoint(10, 315), wxSize(150, 75));
	return temp;
}
