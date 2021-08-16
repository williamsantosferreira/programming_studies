/*
Given an array of integers, return the largest gap between elements of the sorted version of that array.

Here's an illustrative example. Consider the array:

[9, 4, 26, 26, 0, 0, 5, 20, 6, 25, 5]

... which, after sorting, becomes the array:

[0, 0, 4, 5, 5, 6, 9, 20, 25, 26, 26]

... so that we now see that the largest gap in the array is the gap of 11 between 9 and 20.
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> swap(std::vector<int> arr, int i1, int i2){
	int auxiliar;

	auxiliar = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = auxiliar;

	return arr;

}

int print(std::vector<int> arr){
	int n = arr.size();

	for(int i = 0; i < n; i++)
		std::cout<<arr[i]<<" ";

	std::cout<<std::endl;

}

std::vector<int> Bubble_Sort(std::vector<int> arr){
	int n = arr.size();

	for(int i1 = n; i1 > 0; i1--){
		for(int i2 = 0; i2 < i1-1; i2++){
			if(arr[i2] > arr[i2+1])
				arr = swap(arr,i2,i2+1);
						
	}
	}

	return arr;
}

int largestGap(std::vector<int> arr) {
	int n = arr.size(),GAP = 0;

	arr = Bubble_Sort(arr);

	print(arr);

	for(int i = 0; i < n-1; i++){
		if(arr[i+1]-arr[i] > GAP)
			GAP = arr[i+1]-arr[i];
}	

return GAP;
}

int main(){
	std::vector<int> arr;

	arr.push_back(1);
	arr.push_back(15);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(7);

	//sort(arr.begin(),arr.end());
	largestGap(arr);
	


return 0;
}
