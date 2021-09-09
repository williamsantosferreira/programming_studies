/*
Mubashir needs your help in a simple task.

Given an array of integers arr and an integer k, find the lowest positive integer x so that exactly k elements of the given array are less than or equal to x. Return null if the condition does not match.

See below examples for a better understanding:

Examples
lessEqual([3, 7, 6, 1, 10, 3, 20], 4) ? 6
// 1, 3, 3, 6 = 4 elements
// All elements are less than or equal to 6

lessEqual([3, 7, 6, 1, 10, 3, 20], 2) ? null
// 1, 3 = 2 elements
// Not possible to return 3 because we have another 3 in the array

lessEqual([3, 7, 5, 1, 10, 3, 20], 4) ? 5
// 1, 3, 3, 5 = 4 elements
// All elements are less than or equal to 5

lessEqual([10, 15, 20, 25], 0) ? 1
// k = 0

*/

#include <iostream>
#include <vector>

void switch_pos(std::vector<int>& arr,int pos1,int pos2){
	int pos;
	
	pos = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = pos;
	
}

void sorting(std::vector<int>&arr){
	for(int i = arr.size()-1; i > 0; i--){
		for(int w = 0; w < i; w++){
			if(arr[w]>arr[w+1])
				switch_pos(arr,w,w+1);
		}
	}
}

int lessEqual(std::vector<int> arr,int k){
	sorting(arr);
	
	if(k == 0)
		return 1;
	else if(k > arr.size())
		return 0;
	else if(arr[k-1] != arr[k])
		return arr[k-1];
	else
		return 0;	
}

void show_vector(std::vector<int> arr){
	for(int i = 0; i < arr.size(); i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int main(){
	std::vector<int> arr;
	
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(10);
	arr.push_back(3);
	arr.push_back(20);
	
	std::cout<<lessEqual(arr,3);
	
	return 0;
}
