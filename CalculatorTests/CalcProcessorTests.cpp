#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/CalcProcessor.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcProcessorTests
{
	TEST_CLASS(CalcProcessorTests)
	{
	public:

		CalcProcessor* processor = CalcProcessor::GetInstance();
		TEST_METHOD(ProcessorInstanceReturnIsNotNull) {
			Assert::IsNotNull(processor);
		}

		TEST_METHOD(StrValReturns0AfterClear) {
			std::string expectedResult = "0";
			processor->Clear();
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}

		TEST_METHOD(SetStrValSetsValue5) {
			std::string expectedResult = "5";
			processor->SetStrVal("5");
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(CheckForOnlyZeroReturnsEmptyString) {
			std::string expectedResult = "";
			if (processor->CheckForOnlyZero()) {
				processor->SetStrVal("");
			}
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(NumStr3WasAddedToEmptyStrVal) {
			std::string expectedResult = "3";
			if (processor->CheckForOnlyZero()) {
				processor->SetStrVal("");
			}
			processor->AddNumberToStrVal("3");
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(NumStr3WasAddedToCurrentStrVal) {
			std::string expectedResult = "42";
			processor->SetStrVal("4");
			processor->AddNumberToStrVal("2");
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(CharPlusWasAddedToStrVal) {
			std::string expectedResult = "3+";
			processor->SetStrVal("3");
			processor->AddCharToStrVal('+');
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(OperatorWasDeletedWhenCheckedForPrecedingOperator) {
			std::string expectedResult = "3-";
			processor->SetStrVal("3+");
			processor->CheckForRecentOperand();
			processor->AddCharToStrVal('-');
			std::string actualResult = processor->GetStrVal();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(Float5IsReturnedWhenStrValIs5) {
			float expectedResult = 5.0f;
			processor->SetStrVal("5");
			float actualResult = processor->ConvertEquationStringToTotal(processor->GetStrVal());
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}
		TEST_METHOD(Float10IsReturnWhenStrValIs5Plus5) {
			float expectedResult = 10.0f;
			processor->SetStrVal("5+5");
			float actualResult = processor->ConvertEquationStringToTotal(processor->GetStrVal());
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}

		TEST_METHOD(GetDecReturnsFloatValue) {
			float expectedResult = 10.0f;
			processor->SetStrVal("10");
			float actualResult = processor->ConvertEquationStringToTotal(processor->GetStrVal());
			Assert::AreEqual(expectedResult, actualResult);
		}

		TEST_METHOD(GetBinReturnsAllZerosForZero) {
			std::string expectedResult = "0000000000000000";
			processor->SetStrVal("0");
			std::string actualResult = processor->GetBin();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}

		TEST_METHOD(GetBinReturnsCorrectValuePassedIn) {
			std::string expectedResult = "0101010101010101";
			processor->SetStrVal("21845");
			std::string actualResult = processor->GetBin();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}

		TEST_METHOD(GetHexReturns0xForZero) {
			std::string expectedResult = "0x";
			processor->SetStrVal("0");
			std::string actualResult = processor->GetHex();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}

		TEST_METHOD(GetHexReturns5555ForValuePassedIn) {
			std::string expectedResult = "0x5555";
			processor->SetStrVal("21845");
			std::string actualResult = processor->GetHex();
			Assert::AreEqual(expectedResult, actualResult);
			processor->Clear();
		}

	};
}