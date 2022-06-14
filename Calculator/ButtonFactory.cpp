#include "ButtonFactory.h"
#include "CalcFrame.h"
#include "CalcMain.h"

ButtonFactory::ButtonFactory()
{

}

ButtonFactory::~ButtonFactory()
{
}

wxButton* ButtonFactory::CreateNumButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}


wxButton* ButtonFactory::CreateAddButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateSubButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateMultButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateDivButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateParenthButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateClearEntryButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateDecButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateBinButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}

wxButton* ButtonFactory::CreateHexButton(wxWindow* parent, int idNum, const char* label, wxPoint point, wxSize size)
{
    wxButton* temp = new wxButton(parent, idNum, label, point, size);
    return temp;
}
