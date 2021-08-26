#include <iostream>
#include <string>
#include <sstream>

void simplify(std::string str){
	std::stringstream number1,number2;
	bool trigger = false;

	for(int i = 0; i < str.size(); i++){
		if(str[i] == '/')
			trigger = true;

		else if(trigger == false)
			number1<<str[i];
		else
			number2<<str[i];
	}
}


int main(){
	std::string str = "12";
	std::cout<<str.size();
return 0;
}
