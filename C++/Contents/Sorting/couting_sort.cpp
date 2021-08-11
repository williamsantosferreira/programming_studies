#include <iostream>
#include <string>

#define MAX 256 //quantity of characters

void print(char* list, int n){
	for(int i = 0; i < n; i++)
		std::cout<<list[i];

	std::cout<<std::endl;
}

void couting_sort(char* list, int n){
	int count[MAX] = {0};
	char output[n];

	for(int i = 0; i < n; i++)
		count[list[i]]++;
	for(int i = 1; i < MAX; i++)
		count[i]+=count[i-1];

	for(int i = n-1; i>=0; i--){
		output[count[list[i]]-1] = list[i];
		count[list[i]]--;		
}	
	for(int i = 0; i < n; i++)
		list[i] = output[i];
}
int main(){
	char list[]= "williamsantos";
	int n = sizeof(list)/sizeof(list[0]);

	couting_sort(list,n);
	print(list,n);
return 0;
}
