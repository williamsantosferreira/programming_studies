/*
Create a function that takes a vector of vectors as an argument. Each inner vector has 2 elements. The first element is the numerator and the second element is the denominator. Return the sum of the fractions rounded to the nearest whole number.

Examples
sum_fractions({{18, 13}, {4, 5}}) ? 2

sum_fractions({{36, 4}, {22, 60}}) ? 9

sum_fractions({{11, 2}, {3, 4}, {5, 4}, {21, 11}, {12, 6}}) ? 11
*/
#include <iostream>
#include <vector>

int sum_fractions(std::vector<std::vector<int> > arr){
	int n = arr.size();
	int mmc = 1,numerator = 0;
	
	for (int i = 0; i < n; i++)
		mmc = mmc*arr[i][1];
	for (int i = 0; i < n; i++)
		numerator = numerator + ((mmc/arr[i][1])*arr[i][0]);

	return numerator/mmc;
}

int main(){
	std::vector<std::vector<int> > arr;
	std::vector<int> v1,v2;
	
	v1.push_back(36);
	v1.push_back(4);
	
	v2.push_back(22);
	v2.push_back(60);
	
	arr.push_back(v1);
	arr.push_back(v2);

	std::cout<<sum_fractions(arr);
	
	return 0;
}
