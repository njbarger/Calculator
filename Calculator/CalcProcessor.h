#pragma once
#include <string>
#include <vector>
#include <sstream>
class CalcProcessor
{
private:
	static CalcProcessor* _processor;
	int baseNumber = 0;
	int prevNumber = 0;
	std::vector<float> numVec;
	std::vector<char> operandVec;
	std::string strVal = "0";
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
			strVal.back() == '%' || strVal.back() == '(' ||
			strVal.back() == ')')
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
		std::string negCheck = currStr;
		if (negCheck[0] == '-')
		{
			negCheck.erase(0, 1);
			currStr = negCheck;
		}

		std::vector<float> parenthNums;
		bool inParenth = false;
		std::string tempParenthNum;

		std::vector<float> nums;
		std::string tempNum = "";

		std::vector<char> operands;

		for (int i = 0; i < currStr.size(); i++) {
			if (currStr[i] == '+' || currStr[i] == '-' ||
				currStr[i] == '*' || currStr[i] == '/' ||
				currStr[i] == '%' || currStr[i] == '(' ||
				currStr[i] == ')') {


				if (currStr[i] == '(') {
					inParenth = true;
				}
				else if (inParenth && currStr[i] != '(')
				{
					tempParenthNum = tempParenthNum + currStr[i];
				}
				else if (currStr[i] == ')')
				{
					nums.push_back(ConvertEquationStringToTotal(tempParenthNum));
					inParenth = false;
				}
				else {
					nums.push_back(std::stof(tempNum));
					tempNum = "";
					operands.push_back(currStr[i]);
				}
			}
			else if (currStr[i + 1] == '(') {
				nums.push_back(std::stof(tempNum));
				operands.push_back('*');
			}
			else {
				tempNum = tempNum + currStr[i];
			}
			if (i == currStr.size() - 1)
			{
				nums.push_back(std::stof(tempNum));
			}
		}

		float result = DoMath(nums, operands);

		return result;
	}

	float DoMath(std::vector<float> numVec, std::vector<char> opVec) {
		bool dontQuit = true;

		while (dontQuit) {
			for (int i = 0; i < opVec.size();)
			{
				if (opVec[i] == '*' ||
					opVec[i] == '/' ||
					opVec[i] == '%')
				{
					numVec[i] = DoOperator(opVec[i], numVec[i], numVec[i + 1]);
					opVec.erase(opVec.begin() + i);
					numVec.erase(numVec.begin() + i + 1);
				}
				else
					i++;
			}
			for (int i = 0; i < opVec.size();)
			{
				numVec[i] = DoOperator(opVec[i], numVec[i], numVec[i + 1]);
				opVec.erase(opVec.begin() + i);
				numVec.erase(numVec.begin() + i + 1);
			}
			if (numVec.size() == 1)
			{
				dontQuit = false;
			}
		}
		return (float)numVec[0];
	}

	float DoOperator(char op, float x, float y)
	{
		float result = 0;
		switch (op)
		{
		default:
			break;
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		case '%':
			result = (int)x % (int)y;
			break;
		}

		return result;
	}

	float GetDec() {
		float result = ConvertEquationStringToTotal(strVal);
		return result;
	}

	std::string GetHex() {
		std::string result = "";
		int number = ConvertEquationStringToTotal(strVal);

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
		int number = (int)ConvertEquationStringToTotal(strVal);
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

	void AddNumberToStringValue(std::string strNumToAdd) {
		strVal = strVal + strNumToAdd;
	}
	void AddCharToStringValue(char charToAdd) {
		strVal = strVal + charToAdd;
		operandVec.push_back(charToAdd);
	}
	void MakeNegative() {
		std::string negCheck = GetStrVal();
		if (negCheck[0] == '-')
		{
			negCheck.erase(0, 1);
			SetStrVal(negCheck);
		}
		else {
			float floatCompare = ConvertEquationStringToTotal(GetStrVal());
			if (floatCompare == (int)floatCompare) {
				SetStrVal(std::to_string(-1 * (int)ConvertEquationStringToTotal(GetStrVal())));
			}
			else
			{
				SetStrVal(std::to_string(-1 * (ConvertEquationStringToTotal(GetStrVal()))));
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
