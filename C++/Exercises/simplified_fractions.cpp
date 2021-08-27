/*
Create a function that returns the simplified version of a fraction.
Examples
simplify("4/6") ? "2/3"

simplify("10/11") ? "10/11"

simplify("100/400") ? "1/4"

simplify("8/4") ? "2"
*/

#include <iostream>
#include <string>
#include <sstream>

int mdc(int higher,int lower){
	int i = lower;
	
	while(lower > 1){
		if(lower%i == 0 && higher%i == 0)
			return i;
		else if(i != lower && lower%i == 0)
			lower = lower/i;
		else
			i--;	
	}
	return 1;
}

std::string simplify(std::string str){
	std::stringstream number1,number2,result;
	int n1,n2,n;
	
	bool trigger = false;

	for(int i = 0; i < str.size(); i++){
		if(str[i] == '/')
			trigger = true;

		else if(trigger == false)
			number1<<str[i];
		else
			number2<<str[i];
	}
	number1>>n1;
	number2>>n2;
	
	if(n1 > n2){
		n = mdc(n1,n2);
		while(n > 1){
			n1 = n1/n;
			n2 = n2/n;
			
			n = mdc(n1,n2);
		}
	}
	else if(n1 < n2){
		n = mdc(n2,n1);
		while(n > 1){
			n1 = n1/n;
			n2 = n2/n;
		
			n = mdc(n2,n1);
		}
	} 
	else
		return "1";

	if(n2 != 1)
		result<<n1<<"/"<<n2;
	else
		result<<n1;
	
	return result.str();
}

int main(){
	std::string str = "8/4";

	std::cout<<simplify(str);
	
return 0;
}
