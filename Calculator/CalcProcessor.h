#pragma once
#include <string>
#include <vector>
#include <sstream>

#include "IBaseCommand.h"
#include "SeparateIntoNumsAndOps.h"

class CalcProcessor
{
private:
	static CalcProcessor* _processor;
	int baseNumber = 0;
	int prevNumber = 0;
	std::vector<float> numVec;
	std::vector<char> operandVec;
	std::string strVal = "0";
	SeparateIntoNumsAndOps separator;
	CalcProcessor() {} // sets constructor private so only one instance.

public:

	static CalcProcessor* GetInstance() {	// will return static _processor
		if (_processor == nullptr) {
			_processor = new CalcProcessor();
		}
		else
			return _processor;
	}

	std::string GetStrVal() {
		return strVal;
	}

	void SetStrVal(std::string newVal) {
		strVal = newVal;
	}

	CalcProcessor(CalcProcessor& other) = delete;					// makes it so any copies sends an error so no chance of creating duplicate

	void operator=(const CalcProcessor& other) = delete;		// makes it so any copies sends an error so no chance of creating duplicate

	void CheckForRecentOperand() {
		if (strVal.back() == '+' || strVal.back() == '-' ||
			strVal.back() == '*' || strVal.back() == '/' ||
			strVal.back() == '%')
		{
			strVal.pop_back();
		}
	}

	bool CheckForOnlyZero() {
		if (strVal == "0") {
			return true;
		}
		else if (strVal == "") {
			SetStrVal("0");
			return true;
		}
		return false;
	}

	float ConvertEquationStringToTotal(std::string currStr) {

		float result = separator.Execute(currStr);
		return result;
	}

	
	float GetDec() {
		float result = separator.Execute(strVal);
		return result;
	}

	std::string GetHex() {
		std::string result = "";
		int number = separator.Execute(strVal);

		while (number > 0) {
			int mod = (int)number % 16;
			if (mod < 10)
			{
				result = std::to_string(mod) + result;
			}
			else if (mod == 10) {
				result = "A" + result;
			}
			else if (mod == 11) {
				result = "B" + result;
			}
			else if (mod == 12) {
				result = "C" + result;
			}
			else if (mod == 13) {
				result = "D" + result;
			}
			else if (mod == 14) {
				result = "E" + result;
			}
			else if (mod == 15) {
				result = "F" + result;
			}
			number = number / 16;
		}

		result = "0x" + result;
		return result;
	}

	std::string GetBin() {
		std::string result = "";
		int number = (int)separator.Execute(strVal);
		for (int i = 0; i < 32; i++) {
			if (number % 2 == 0) {
				result = "0" + result;
			}
			else {
				result = "1" + result;
			}
			number = number / 2;
		}
		return result;
	}

	void AddNumberToStrVal(std::string strNumToAdd) {
		strVal = strVal + strNumToAdd;
	}
	void AddCharToStrVal(char charToAdd) {
		CheckForRecentOperand();
		strVal = strVal + charToAdd;
		operandVec.push_back(charToAdd);
	}
	std::string MakeNegative() {
		std::string negCheck = GetStrVal();
		if (negCheck[0] == '-')
		{
			negCheck.erase(0, 1);
			return (negCheck);
		}
		else {
			float floatCompare = ConvertEquationStringToTotal(GetStrVal());
			if (floatCompare == (int)floatCompare) {
				return (std::to_string((int)(-1 * floatCompare)));
			}
			else {
				return (std::to_string(-1 * floatCompare));
			}
		}
	}
	int Equals() {
		int result = ConvertEquationStringToTotal(strVal);
		return result;
	}
	void Clear() {
		strVal = "0";
	}
	void ClearEntry() {
		if (!CheckForOnlyZero()) {
			for (int i = strVal.size() - 1; i >= 0; i--)
			{
				if (strVal[i] == '+' || strVal[i] == '-' ||
					strVal[i] == '*' || strVal[i] == '/' ||
					strVal[i] == '%' || strVal[i] == '(' ||
					strVal[i] == ')') {

					strVal.pop_back();
					break;
				}
				else
				{
					strVal.pop_back();
				}
			}
		}
		else {
			strVal = "0";
		}

	}

};

CalcProcessor* CalcProcessor::_processor = nullptr;
