#include <iostream>

void insertion_sort(int* vector, int n){
	int SWAP, POS;

	for(int i1 = 1; i1 < n; i1++){
		SWAP = vector[i1];
		POS = i1-1;

		for(int i2 = i1; i2 > 0; i2--){
			if(SWAP < vector[POS] && POS >= 0){
				vector[POS+1] = vector[POS];
				POS = POS-1;
			}
		}
		vector[POS+1] = SWAP;
	}
}

void show_vector(int* vector, int n){
	for(int i = 0; i < n; i++){
		std::cout<<vector[i]<<" ";
	}
	std::cout<<std::endl;
}

int main(){
	int list[] = {42,33,23,74,44,67,49};
	int n = 7;

	insertion_sort(list,n);
	show_vector(list,n);
	
return 0;
}
