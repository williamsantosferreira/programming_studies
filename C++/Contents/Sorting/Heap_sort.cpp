#include <iostream>

void print(int* list, int n){
	for(int i = 0; i < n; i++)
		std::cout<<list[i]<<" ";
	std::cout<<std::endl;
}

void swap(int* list,int low,int up){	
	int auxiliar;
	
	auxiliar = list[low];
	list[low] = list[up];
	list[up] = auxiliar;
}

void sort(int* list, int n){
	int left = 0,right = 0,l = 0;
	int auxiliar;

	while(2*l+3 < n)
		l++;
	for(int i = l; i >= 0; i--){
		left = 2*i+1;
		right = 2*i+2;

		if(left < n && list[i] < list[left])
			swap(list,i,left);			
		if(right < n && list[i] < list[right])
			swap(list,i,right);			
	}
	swap(list,0,n-1);
}
void Heap_Sort(int* list, int n){
	for(int i = n; i > 0; i--)
		sort(list,i);
}
int main(){
	int list[]={170,45,75,90,802};
	int n = sizeof(list)/sizeof(list[0]);

	Heap_Sort(list,n);
	print(list,n);

return 0;
}
