#include <iostream>


void shell_sort(int* vector, int n){
     int GAP,i,k,aux,j;
     i = 0;
     k = 2;
     GAP = n/2;
     
     while(GAP > 0){
          if(vector[GAP+i]<vector[i]){
           
              aux = vector[GAP+i];
              vector[GAP+i] = vector[i];
              vector[i] = aux;
		
	      j = i - GAP;

              while(vector[j+GAP]<vector[j] && j >= 0){
              
		aux = vector[j+GAP];
		vector[j+GAP] = vector[j];
		vector[j] = aux;

		j = j - GAP;
              }

          }
       
         i++;

         if((i+GAP) == n){
       		k*=2;
       		GAP = n/k;
      		i = 0;
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
	int list[]={42,33,23,74,44,67,49};
	
	show_vector(list,7); 	
	
        shell_sort(list,7);

        show_vector(list,7);

return 0;
}
