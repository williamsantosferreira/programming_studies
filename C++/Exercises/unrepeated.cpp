/*
Create a function that will remove any repeated charcter(s) in a word passed to the function. Not just consecutive characters, but characters repeating anywhere in the input.

Examples
unrepeated("hello") ? "helo"

unrepeated("aaaaa") ? "a"

unrepeated("WWE!!!") ? "WE!"

unrepeated("call 911") ? "cal 91"
*/

#include <iostream>
#include <string>

#define characters 256

std::string unrepeated(std::string str){
	bool table[characters]={false};
	std::string msg;
	
	for(int i = 0; i < str.size(); i++){
		if(table[int(str[i])] == false)
			msg = msg + str[i];
			
		table[int(str[i])] = true;
	}
	return msg;
}


int main(){
	std::string str("call 911");
	
	std::cout<<unrepeated(str);
	
	return 0;
}
