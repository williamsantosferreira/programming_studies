/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer.
*/

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

std::string without_duplicates(std::string str){
	HashTable *hash;
	hash = new HashTable;
	int hash_value;
	init_hash(hash);

	
	for(int i = 0; i < str.length(); i++){
		hash_value = HashFunction(str[i]);
		
		if(hash->map[hash_value] == 1){
			str.erase(i,1);
			i--;
		}
		hash->map[hash_value] = 1;
	}
	return str;
}

int main(){
	std::string str("FOLLOW UP");
	
    str = without_duplicates(str);
	
	std::cout<<str;

	return 0;
}
