/*
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
Example: 

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}
Output: 4
Explanation: The missing number from 1 to 5 is 4
*/

#include <iostream>

//To sort my vector I'm going to use a Quick Sort code.

void swap(int* list,int low,int up){
       int aux;
       aux = list[up];
       list[up] = list[low];
       list[low] = aux;
}

void quick_sort(int* list, int LOW, int UP,int pivot){    
	if(UP < pivot){
            if(list[UP]<=list[pivot]){            
		LOW++;
		swap(list,LOW,UP);	
	}
	    UP++;
            quick_sort(list,LOW,UP,pivot);
	}
       else{
	swap(list,LOW+1,UP);
	 if(LOW+1 != pivot)
		quick_sort(list,LOW+1,LOW+2,UP);
	 if(LOW>0)
		quick_sort(list,-1,0,LOW);
	}

}
void show_vector(int* vector,int n){
	for(int i = 0; i < n; i++){
		std::cout<<vector[i]<<" ";
	}
	std::cout<<std::endl;
}

int missing_number(int* vec,int n){
    for(int i = 1; i < n; i++){
        if(vec[i]-vec[i-1] > 1)
            return vec[i-1]+1;
    }
    if(vec[0] != 1)
        return 1;
    return 0;
}

int main(){
    int vec[]={ 4, 6, 5, 3,2};
    int n = sizeof(vec)/sizeof(int);

    quick_sort(vec,-1,0,n-1);

    show_vector(vec,n);

    std::cout<<missing_number(vec,n);
}

