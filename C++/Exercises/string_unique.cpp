//Implement an algorithm to determine if a string has all unique characters.

#include <iostream>
#include <string>

#define PARAM 256

struct HashTable{
	int map[PARAM];
};

int HashFunction(char letter){
	return letter%PARAM;
}

void init_hash(HashTable *hash){
	for(int i = 0; i < PARAM; i++)
		hash->map[i] = 0;

}

bool string_unique(std::string str){
	HashTable* hash;
	hash = new HashTable;
	int hash_value;
	init_hash(hash);
	
	for(int i = 0; i < str.length(); i++){
		hash_value = HashFunction(str[i]);
		if(hash->map[hash_value] == 1)
			return false;
		hash->map[hash_value] = 1;
	}
	return true;
}

int main(){
	std::string str;
	
	std::cout<<"Type any string and the program will verify if all the caracteres are unique: ";
		getline(std::cin,str);
	
	std::cout<<"String: "<<str<<std::endl;
	
	if(string_unique(str))
		std::cout<<"All caracteres of the string are unique!";
	else
		std::cout<<"Not all caracteres of the string are unique!";
	

	return 0;
}
