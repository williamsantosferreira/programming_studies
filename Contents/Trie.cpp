#include <iostream>D
#include <string>
const int ALPHABET_SIZE = 26;

struct Trie{
	Trie *children[ALPHABET_SIZE];
	
	bool isEndOfWorld;
};

Trie*  new_trie(){
	Trie *node = new Trie;
	
	node->isEndOfWorld = false;
	
	for(int i=0;i<ALPHABET_SIZE;i++)
		node->children[i] = NULL;
		
	return node;
}

void insert(Trie *node,std::string key){
	Trie *pCrawl = node;
	
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
			pCrawl->children[index] = new_trie();
			
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWorld = true;
}



int main(){
	Trie *teste = new_trie();
	
	return 0;
}
