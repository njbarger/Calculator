#pragma once
#include <string>

 class IBaseCommand {
 public:
	 virtual float Execute() {
		 return 0;
	 }
	 virtual void AddCharToStrVal(char charToAdd) {

	 }
	 virtual void AddNumberToStrVal(std::string numToAdd) {

	 }
	 virtual bool CheckForOnlyZero() {
		 return true;
	 }
	 virtual std::string GetStrVal()
	 {
		 return "";
	 }
	 virtual void SetStrVal(std::string currStrVal) {

	 }
	 virtual std::string MakeNegative() {
		 return "";
	 }
	 virtual void CheckForRecentOperand() {

	 }
	 virtual float GetDec() {
		 return 0.0;
	 }
	 virtual std::string GetBin() {
		 return "";
	 }
	 virtual std::string GetHex() {
		 return "";
	 }
	 virtual void ClearEntry() {

	 }
	 virtual void Clear() {

	 }



};
