//Merge Sort
#include <iostream>

#define size(x) (sizeof(x)/sizeof(x[0]))

void show_array(int arr[],int n){
	for(int i = 0; i < n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}
void merge(int array[],int l,int m,int r){
	int size_arrayOne = m - l + 1;
	int size_arrayTwo = r - m;

	int* arrayOne = new int[size_arrayOne];
	int* arrayTwo = new int[size_arrayTwo];
	
	for(int i = 0; i < size_arrayOne; i++){
		arrayOne[i] = array[l+i];
	}
	for(int i = 0; i < size_arrayTwo; i++){
		arrayTwo[i] = array[m+1+i];
	}

	int indexOne = 0,indexTwo = 0, indexMerged = l;
	while(indexOne < size_arrayOne && indexTwo < size_arrayTwo){
		if(arrayOne[indexOne] <= arrayTwo[indexTwo]){
			array[indexMerged] = arrayOne[indexOne];
			indexOne++;
		}
		else{
			array[indexMerged] = arrayTwo[indexTwo];
			indexTwo++;
		}
		indexMerged++;
	}
	while(indexOne < size_arrayOne){
		array[indexMerged] = arrayOne[indexOne];
		indexOne++;
		indexMerged++;
	}
	while(indexTwo < size_arrayTwo){
		array[indexMerged] = arrayTwo[indexTwo];
		indexTwo++;
		indexMerged++;
	}	
}

void mergeSort(int arr[],int l,int r){
	
	if(l<r){
		int m = l + (r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main(){
	//Example Array
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	std::cout<<"Unsorted Array:"<<std::endl;
	show_array(arr,size(arr));
	
	mergeSort(arr,0,size(arr)-1);
	
	std::cout<<"Sorted Array: "<<std::endl;
	show_array(arr,size(arr))
;		
	return 0;
}
