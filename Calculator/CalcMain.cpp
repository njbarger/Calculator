#include "CalcMain.h"

// Generate main (entry point)
wxIMPLEMENT_APP(CalcMain);

CalcMain::CalcMain()
{

}
CalcMain::~CalcMain()
{

}


bool CalcMain::OnInit()
{
	mainWindow = new CalcFrame();
	mainWindow->SetMaxClientSize(wxSize(500, 570));
	mainWindow->SetMinClientSize(wxSize(500, 570));
	mainWindow->Show();

	return true;
}