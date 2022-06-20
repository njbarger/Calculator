#pragma once
#include <string>
#include <vector>
class CalcProcessor
{
private:
	static CalcProcessor* _processor;
	float baseNumber = 0.0f;
	std::string strVal = "";
	std::vector<std::string> currVals;
	CalcProcessor() {} // sets constructor private so only one instance.

public:
	static CalcProcessor* GetInstance() {	// will return static _processor
		if (_processor == nullptr) {
			_processor = new CalcProcessor();
		}
		else
			return _processor;
	}

	void SetBaseNumber(float number) {	// Set the number value
		baseNumber = number;
	}
	void AddToCurrVals(std::string currVal) {
		currVals.push_back(currVal);
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
		int number = (int)baseNumber;
		int mod = number % 3;
		for (int i = 0; i < 32; i++) {
			if (mod == 0) {
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
		baseNumber = std::stoi(strVal);
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

};

