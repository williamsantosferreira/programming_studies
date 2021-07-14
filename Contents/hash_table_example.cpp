//This code is implementing a HASH_TABLE - Linear Probing, Quadratic Probing, Double Hashing
#include <iostream>
#include "Hash_Table.h"

int main(){
	std::cout<<"That's an example program to ilustrate HASH_TABLE concept"<<std::endl;
	std::cout<<"There are three basics types of colisions functions (without linked list)\n1.Linear Probing\n2.Quadratic Probing\n3. Double Hashing\nHere we'll' show these 3 types, let's go!"<<std::endl;
	
	int array1[] = {10,11,12,13,14,15,16,17,18,19};
	int array2[] = {10,24,13,98,23,12,53,48,143,200};
	
	Hash_Table hash0,hash1,hash2;
	
	std::cout<<"First, let's use a array1 without any colision\n"<<std::endl;
	
	for(int i = 0; i < 10; i++){
		hash0.add_element(array1[i],0); //linear
		hash1.add_element(array1[i],1); // quadratic
		hash2.add_element(array1[i],2); // double hashing
	}
	
	std::cout<<"\nLINEAR PROBING:"<<std::endl;
	hash0.list();
	
	std::cout<<"\nQUADRATIC PROBING:"<<std::endl;
	hash1.list();
	
	std::cout<<"\nDOUBLE HASHING:"<<std::endl;
	hash2.list();
	
	std::cout<<"-------------------------------"<<std::endl;
	
	hash0.clear();
	hash1.clear();
	hash2.clear();
	
	for(int i = 0; i < 10; i++){
		hash0.add_element(array2[i],0); 
		hash1.add_element(array2[i],1); 
		hash2.add_element(array2[i],2); 
	}
	std::cout<<"Now, we have some colisions"<<std::endl;
	
	std::cout<<"\nLINEAR PROBING:"<<std::endl;
	hash0.list();
	
	std::cout<<"\nQUADRATIC PROBING:"<<std::endl;
	hash1.list();
	
	std::cout<<"\nDOUBLE HASHING PROBING:"<<std::endl;
	hash2.list();
	
	return 0;
}
