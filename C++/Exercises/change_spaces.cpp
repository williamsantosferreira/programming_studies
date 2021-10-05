//Write a method to replace all spaces in a string with ‘%20’.

#include <iostream>
#include <string>

std::string change_spaces(std::string str){
	while(str.find(" ") < str.size())
		str = str.substr(0,str.find(" "))+ "%20" + str.substr(str.find(" ")+1);
	return str;
}

int main(){
	std::string str("William Santos Ferreira");

	std::cout<<change_spaces(str);
	
	
	return 0;
}
