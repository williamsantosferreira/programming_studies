#include <iostream>
#include <string>

#define MAX 256

struct HashTable{
	int table[MAX];
	int count[MAX];
};

void init_hash(HashTable* hash){
	for(int i = 0; i < MAX; i++){
		hash->table[i] = 0;
		hash->count[i] = 0;
	}
}

int HashFunction(char letter){
	return letter%MAX;
}

void print_hash(HashTable* hash){
	for(int i = 0; i < MAX; i++){
		std::cout<<i<<": "<<hash->table[i]<<" count: "<<hash->count[i]<<std::endl;
	}
}

bool anagram_verify(std::string str1, std::string str2){
	int hash_value;
	HashTable* hash;
	hash = new HashTable;
	
	init_hash(hash);
	
	for(int i = 0; i < str1.size(); i++){
		hash_value = HashFunction(str1[i]);
		if(hash->table[hash_value] == 1)
			hash->count[hash_value] = hash->count[hash_value] + 1;
		else{
			hash->table[hash_value] = 1;
			hash->count[hash_value] = 1;
		}
	}
	
	for(int i = 0; i < str2.size(); i++){
		hash_value = HashFunction(str2[i]);
		if(hash->table[hash_value] == 0)
			return false;
		else{
			hash->count[hash_value] = hash->count[hash_value] - 1;
		}
	}
	
	for(int i = 0; i < MAX; i++){
		if(hash->count[i] != 0)
			return false;
	}
	return true;
}

int main(){
	std::string str1("night"),str2("thing");
	
	std::cout<<anagram_verify(str1,str2);
	
	return 0;
}
