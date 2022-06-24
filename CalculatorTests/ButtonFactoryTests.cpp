#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/CalcFrame.h"
#include "../Calculator/ButtonFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
		ButtonFactory buttonFactory;
		wxFrame* frame = new wxFrame();



		TEST_METHOD(NumButtonHasProperID) {
			wxButton* num1Button = buttonFactory.CreateNumButton(frame, 1, "1", wxPoint(0, 0));
			int expected = 1;
			int actual = num1Button->GetId();
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(NumButtonHasIncorrectID) {
			wxButton* num1Button = buttonFactory.CreateNumButton(frame, 1, "1", wxPoint(0, 0));
			int wrongAnswer = 3;
			int actual = num1Button->GetId();
			Assert::AreNotEqual(wrongAnswer, actual);
		}

		TEST_METHOD(NumArrayHasAllNumbers) {
			wxButton* buttonArray[10] = {};
			buttonFactory.CreateNumButtonArray(frame, buttonArray);
			int expectedNumbers = 0;
			for (int i = 0; i < 10; i++)
			{
				if (i == buttonArray[i]->GetId()) {
					expectedNumbers++;
				}
			}
			Assert::AreEqual(expectedNumbers, 10);
		}

		TEST_METHOD(NumArrayAt5has5) {
			wxButton* buttonArray[10] = {};
			buttonFactory.CreateNumButtonArray(frame, buttonArray);
			int expectedNumber = 5;
			int actualNumber = buttonArray[5]->GetId();
			Assert::AreEqual(expectedNumber, actualNumber);
		}

		TEST_METHOD(NumButton9hasValue9) {
			wxButton* buttonArray[10] = {};
			buttonFactory.CreateNumButtonArray(frame, buttonArray);
			int expectedNumber = 9;
			int actualNumber = buttonArray[9]->GetId();
		}

		TEST_METHOD(PlusButtonCreated) {
			wxButton* plusButton = buttonFactory.CreateAddButton(frame);
			Assert::IsNotNull(plusButton);
		}

		TEST_METHOD(PlusButtonHasProperLabel) {
			wxButton* plusButton = buttonFactory.CreateAddButton(frame);
			plusButton->SetLabel("+");
			bool isEqual = false;
			wxString expected = "+";
			wxString actual = plusButton->GetLabel();
			if (expected == actual) {
				isEqual = true;
			}
			Assert::IsTrue(isEqual);
		}

		TEST_METHOD(GetBinHasId19) {
			wxButton* binButton = buttonFactory.CreateBinButton(frame);
			int expected = 19;
			int actual = binButton->GetId();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetBinIdNOT17) {
			wxButton* binButton = buttonFactory.CreateBinButton(frame);
			int expected = 17;
			int actual = binButton->GetId();
			Assert::AreNotEqual(expected, actual);
		}

		TEST_METHOD(GetHexHasId20) {
			wxButton* hexButton = buttonFactory.CreateHexButton(frame);
			int expected = 20;
			int actual = hexButton->GetId();
			Assert::AreEqual(expected, actual);
		}


	};
}