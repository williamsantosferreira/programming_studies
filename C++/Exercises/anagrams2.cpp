#include <iostream>
#include <string>

std::string BubbleSort(std::string str){
	char letter;
	for(int i = 0; i < str.size(); i++){
		for(int i1 = i; i1 < str.size(); i1++){
			if(str[i] > str[i1]){
				letter = str[i];
				str[i] = str[i1];
				str[i1] = letter;	
			}
		}
	}
	return str;
}

bool anagram_verify(std::string str1,std::string str2){
	str1 = BubbleSort(str1);
	str2 = BubbleSort(str2);
	if(str1 == str2)
		return true;
	else
		return false;
}

int main(){
	std::string str1("race"),str2("care");
	
	std::cout<<anagram_verify(str1,str2);
	return 0;
}
