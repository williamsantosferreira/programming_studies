#include <iostream>

//Return the number of digits of the highest value on the list
int digits(int* list, int n){
	int max = list[0], j;
	for(int i = 0; i < n; i++){
		if(list[i]>max)
			max = list[i];
	}
	for(j = 0; max>0; j++){
		max =  max/10;
	}
	return j;
}

//I did'nt know this sort, so I'm going to do a code of it.
void counting_sort(int* list, int n,int exp){
	int count[10] = {0};
	int output[n];

	for(int i = 0; i < n; i++)
		count[(list[i]/exp)%10]++;

	for(int i = 1; i < 10; i++)
		count[i]+= count[i-1];

	for(int i = n-1; i >= 0; i--){
		output[count[(list[i]/exp)%10]-1] = list[i];
		count[(list[i]/exp)%10]--;
	}

	for(int i = 0; i < n; i++)
		list[i] = output[i];

}

void radix_sort(int* list,int n){
	int exp,max;

	max = digits(list,n);
	exp = 1;
	for(int i = 0;i < max; i++){
		exp*=10;
		counting_sort(list,n,exp);
}
}

void print(int* list, int n){
	for(int i = 0; i < n; i++)
		std::cout<<list[i]<<std::endl;
}

int main(){
	int list[]={170,45,75,90,802,24,2,66};
	int n = sizeof(list)/sizeof(list[0]);

	radix_sort(list,n);
	print(list,n);

return 0;
}
