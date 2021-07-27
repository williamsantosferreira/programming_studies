#include <iostream>

void selection_sort(int* vector, int n){
	int min, LOC, auxiliar;

	for(int i1 = 0; i1 < n; i1++){		
	    	min = vector[i1];
		LOC = -1;
		for(int i2 = i1+1; i2 < n; i2++){
			if(vector[i2] < min)
				LOC = i2;
		}
		if(LOC > 0){
			auxiliar = vector[LOC];
			vector[i1] = auxiliar;
			vector[LOC] = min;
		}
	}	
}
void show_vector(int* vector, int n){
	for(int i = 0; i < n; i++)
		std::cout<<vector[i]<<" ";
	std::cout<<std::endl;
}

int main(){
	int list[] = {42,33,23,74,44}, n = 5;

	selection_sort(list,n);
	show_vector(list,n);
return 0;
}
