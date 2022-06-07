#pragma once
#include "CalcFrame.h"

class CalcMain : public wxApp
{
public:
	CalcMain();
	~CalcMain();
	bool OnInit();

private:
	CalcFrame* mainWindow = nullptr;

};

