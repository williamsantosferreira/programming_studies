#include <iostream>
int linear_searching(int* list, int n,int value){
	for(int i = 0; i < n; i++){
		if(value == list[i])
			return i;
}
	return -1;
}

int main(){
	int list[]={10,25,12};

	std::cout<<linear_searching(list,3,250)<<std::endl;

return 0;
}
