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
	mainWindow->Show(true);

	return true;
}