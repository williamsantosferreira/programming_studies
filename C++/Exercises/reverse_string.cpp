//Write code to reverse a C-Style String

#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 100

void reverse_string(char str[]){
	int n = strlen(str);
	char buffer;
	for(int i = 0; i< n/2; i++){
		std::cout<<str[i]<<" "<<str[(n-1)-i]<<std::endl;
		buffer = str[i];
		str[i] = str[(n-1)-i];
		str[(n-1)-i] = buffer;
	}
	std::cout<<str;
}

int main(){
	char str[MAX];
	scanf("%99[^\n]",str);
	
	reverse_string(str);
	return 0;
}
