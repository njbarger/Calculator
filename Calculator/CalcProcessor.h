#pragma once
#include <string>
#include <vector>
class CalcProcessor
{
private:
	static CalcProcessor* _processor;
	int baseNumber = 0;
	int prevNumber = 0;
	std::string strVal = "";
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
	void SetNewValue() {
		prevNumber = baseNumber;
		baseNumber = 0;
	}


	void SetBaseNumber(int number) {	// Set the number value
		baseNumber = number;
	}
	int GetBaseNumber() {
		return baseNumber;
	}
	void SetPrevNumber(int number) {
		prevNumber = number;
	}
	int GetPrevNumber() {
		return prevNumber;
	}
	CalcProcessor(CalcProcessor& other) = delete;					// makes it so any copies sends an error so no chance of creating duplicate
	void operator=(const CalcProcessor& other) = delete;		// makes it so any copies sends an error so no chance of creating duplicate

	std::string GetDec() {
		return std::to_string(baseNumber);
	}

	std::string GetHex() {
		std::string result = "";
		int number = (int)baseNumber;

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
		int number = baseNumber;
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
		if (prevNumber > 0) {
			std::string tempStr = strVal;
			for (int i = 0; i < std::to_string(prevNumber).length(); i++) {
				tempStr.erase(0, 1);
			}
			baseNumber = std::stoi(tempStr);
		}
		else {
			baseNumber = std::stoi(strVal);
		}
	}
	void AddCharToStringValue(char charToAdd) {
		strVal = strVal + charToAdd;
	}
	void MakeNegative() {
		baseNumber = -1 * baseNumber;
	}
	/*void Add() {

	}
	void Sub() {

	}
	void Mult() {

	}
	void Div() {

	}
	void Mod() {

	}
	void OpenParenth() {

	}
	void CloseParenth() {

	*/
	void Equal() {

	}
	void Clear() {
		baseNumber = 0;
		prevNumber = 0;
		strVal = "0";
	}
	void ClearEntry() {
		std::string numStr = std::to_string(baseNumber);
		for (int i = 0; i < numStr.length() + 1; i++) {
			strVal.pop_back();
		}
		baseNumber = prevNumber;

	}

};

CalcProcessor* CalcProcessor::_processor = nullptr;
