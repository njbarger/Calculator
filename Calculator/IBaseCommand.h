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
};
