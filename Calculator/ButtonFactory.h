#pragma once
#include "wx/wx.h"


class ButtonFactory
{
private:

public:
	ButtonFactory();
	~ButtonFactory();

	void CheckEventId(int id);

	wxButton* CreateNumButton(wxWindow* parent, int idNum, const char* label, wxPoint point);

	void CreateNumButtonArray(wxWindow* parent, wxButton** buttonArray);
	
	wxButton* CreateAddButton(wxWindow* parent);
	wxButton* CreateSubButton(wxWindow* parent);
	wxButton* CreateMultButton(wxWindow* parent);
	wxButton* CreateDivButton(wxWindow* parent);
	wxButton* CreateModuloButton(wxWindow* parent);
	wxButton* CreateEqualsButton(wxWindow* parent);
	wxButton* CreateParenthButton(wxWindow* parent);
			
	wxButton* CreateNegativeButton(wxWindow* parent);

	wxButton* CreateDecimalPointButton(wxWindow* parent);
			
	wxButton* CreateClearButton(wxWindow* parent);
	wxButton* CreateClearEntryButton(wxWindow* parent);
			
	wxButton* CreateDecButton(wxWindow* parent);
	wxButton* CreateBinButton(wxWindow* parent);
	wxButton* CreateHexButton(wxWindow* parent);

	
};

