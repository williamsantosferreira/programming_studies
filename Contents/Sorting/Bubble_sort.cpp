#include<iostream>

void bubble_sort(int* vector, int n){
	int auxiliar;
		
	for(int i1 = n; i1 > 0; i1--){
		for(int i2 = 0; i2 < i1-1; i2++){
			if(vector[i2] > vector[i2+1]){
				auxiliar = vector[i2+1];
				vector[i2+1] = vector[i2];
				vector[i2] = auxiliar;
                        }	
		}
	}

}

void show_vector(int* vector,int n){
	for(int i = 0; i < n; i++){
		std::cout<<vector[i]<<" ";
	}
	std::cout<<std::endl;
}


int main(){
	int n = 6;
	int list[] = {33, 12, 44, 31, 67, 19};

	bubble_sort(list,n);
	show_vector(list,n);

return 0;
}
