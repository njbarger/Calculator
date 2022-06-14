#pragma once
#include "wx/wx.h"


class ButtonFactory
{
private:

public:
	ButtonFactory();
	~ButtonFactory();



	wxButton* CreateNumButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	
	wxButton* CreateAddButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateSubButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateMultButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateDivButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateModuloButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateEqualsButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateParenthButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
			
	wxButton* CreateNegativeButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
			
	wxButton* CreateClearButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateClearEntryButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
			
	wxButton* CreateDecButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateBinButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);
	wxButton* CreateHexButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size);


};

