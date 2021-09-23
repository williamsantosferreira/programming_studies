/*
Create a function that takes the dimensions of two triangles (as arrays) and checks if the first triangle fits into the second one.

Examples
doesTriangleFit([1, 1, 1], [1, 1, 1]) ? true

doesTriangleFit([1, 1, 1], [2, 2, 2]) ? true

doesTriangleFit([1, 2, 3], [1, 2, 2]) ? false

doesTriangleFit([1, 2, 4], [1, 2, 6]) ? false
Notes
Triangle fits if it has the same or smaller size as the hole.
The function should return false if the triangle with that dimensions is not possible.
*/

#include <iostream>
#include <vector>
#include <cmath>

int triangle_true(std::vector<int> triangle){
	int a,b,c;
	a = triangle[0];
	b = triangle[1];
	c = triangle[2];
	
	if((a+b)>c && (a+c)>b && (b+c)>a)
		return 1;
	return 0;
}

bool triangleFit(std::vector<int> t1, std::vector<int> t2){
	if(!(triangle_true(t1) && triangle_true(t2)))
		return false;
	if(t1[0]<=t2[0] && t1[1]<=t2[1] && t1[2]<=t2[2])
		return true;
	else
		return false;
}

int main(){
	std::vector<int> t1,t2;
	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(4);
	
	t2.push_back(1);
	t2.push_back(2);
	t2.push_back(6);
	
	if(triangleFit(t1,t2))
		std::cout<<"True"<<std::endl;
	else
		std::cout<<"False"<<std::endl;
	
}
