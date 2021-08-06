/*
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
Example: 

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5
*/

//I'm write two solutions
//First one using just math
//Second one using XOR

#include <iostream>

int missing_number(int* list,int n){
	int number;

	for(int i = 1; i < n; i++){
		if(list[i]-list[i-1] > 1)
			return list[i-1]+1;
	}
return 1;
}

int missing_number_XOR(int* list, int n){
/*
Uma propriedade interessante

a1 ^ a2 ^ ... ^ an = a (um valor qualquer)
a1 ^ a2 ^ ... ^ a(n-1) = b (perceba que b se diferencia de a, pelo an)

a ^ b = an, ele é o elemento que faltava
*/
	int a = 1,b = list[0];

	for(int i = 1; i < n; i++)
		b = b ^ list[i];
	for(int i = 2; i <= n+1; i++)
		a = a^i;
	return a^b;
}

int main(){
	int list[]={1,2,3,5}, n = 4;
	
	std::cout<<"Missing Number using sum and XOR:\n"<<"Missing number = "<<missing_number(list,n)<<"\nMissing number = "<<missing_number_XOR(list,n)<<std::endl;
return 0;
}
