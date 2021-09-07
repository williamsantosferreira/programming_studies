/*
Create a function that determines if a given sequence is linear, quadratic or cubic. The input will be an array of numbers of varying lengths. The function should return "Linear", "Quadratic" or "Cubic".

Examples
seqLevel([1, 2, 3, 4, 5]) ? "Linear"

seqLevel([3, 6, 10, 15, 21]) ? "Quadratic"

seqLevel([4, 14, 40, 88, 164]) ? "Cubic"
*/

#include <iostream>
#include <string>
#include <vector>

std::string seqLevel(std::vector<int> arr){
	std::string answer;
	std::vector<int> v1,v2;
	int i;
	
	v1 = arr;
	
	for(i = 1; i < 10; i++){
		if((v1[1]-v1[0] == v1[2]-v1[1]) || v1.size() < 2 )
			break;
		else{
			v2.clear();
			for(int w = 1; w < v1.size(); w++)
				v2.push_back(v1[w]-v1[w-1]);
			v1 = v2;
		}	
	}
		if(i == 1)
			return "Linear";
		else if(i == 2)
			return "Quadratic";
		else if(i == 3)
			return "Cubic";
		else
			return ">3";			
}


int main(){
	std::vector<int> arr;
	
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(10);
	arr.push_back(15);
	arr.push_back(21);
	
	std::cout<<seqLevel(arr);
	
	return 0;
}
