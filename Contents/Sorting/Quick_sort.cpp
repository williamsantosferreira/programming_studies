#include <iostream>


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

int main(){
	int list[]={10,11,0,2,15,17,32};
	quick_sort(list,-1,0,6);
        show_vector(list,7);
return 0;
}

