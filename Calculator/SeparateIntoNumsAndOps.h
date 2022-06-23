#pragma once
#include "IBaseCommand.h"
#include <string>
#include <vector>

class SeparateIntoNumsAndOps : public IBaseCommand {
private:
	std::vector<int> numVec;
	std::string tempNumStr = "";
	std::vector<char> opVec;
public:
	float Execute(std::string currStr) {
		float result = SeparateString(currStr);
		tempNumStr = "";
		numVec.clear();
		opVec.clear();
		return result;
	}

	float SeparateString(std::string currStr) {
		for (int i = 0; i < currStr.size(); i++) {

			if (i == 0 && currStr[i] == '-') {
				tempNumStr.push_back(currStr[i]);
				i++;
			}
			if (currStr[i] == '+' || currStr[i] == '-' ||
				currStr[i] == '*' || currStr[i] == '/' ||
				currStr[i] == '%') {

				//
				//    Save for future parenthesis logic
				//
				/*if (currStr[i] == '(') {
					int numOfOpenParenth = 1;
					int numOfCloseParenth = 0;
					for (int j = i + 1; j < currStr.size(); j++) {
						if (currStr[j] == '(') {
							numOfOpenParenth++;
							continue;
						}
						if (currStr[j] == ')')
						{
							numOfCloseParenth++;
							if (numOfOpenParenth == numOfCloseParenth) {
								tempParenthNum = ConvertEquationStringToTotal(tempParenthNumStr);
							}
						}
						tempParenthNumStr = tempParenthNumStr + currStr[j];
					}


					if (i != 0) {

						if (!currStr[i - 1] == '+' || !currStr[i - 1] == '-' ||
							!currStr[i - 1] == '*' || !currStr[i - 1] == '/' ||
							!currStr[i - 1] == '%') {

							operands.push_back('*');
						}
						else {
							nums.push_back(ConvertEquationStringToTotal(tempNumStr));
							operands.push_back(currStr[i]);
						}
					}
					inParenth = true;
					continue;
				}*/


				numVec.push_back(std::stof(tempNumStr));
				tempNumStr = "";
				opVec.push_back(currStr[i]);
			}
			else {
				tempNumStr = tempNumStr + currStr[i];
			}
			if (i == currStr.size() - 1)
			{
				numVec.push_back(std::stof(tempNumStr));
			}
		}

		float result = DoMath();

		return result;
	}

	float DoMath() {
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

	float DoOperator(char op, int x, int y) {
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

};