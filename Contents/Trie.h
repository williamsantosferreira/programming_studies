#include <iostream>
#include <string>
const int ALPHABET_SIZE = 26;

struct Trie{
	Trie *children[ALPHABET_SIZE];
	
	bool isEndOfWord;
};

Trie*  new_trie(){
	Trie *node = new Trie;
	
	node->isEndOfWord = false;
	
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
	pCrawl->isEndOfWord = true;
}

int search(Trie *node,std::string word){
	int length = word.length();
	
	Trie *root = node;
	
	for(int i=0;i<length;i++){
		int index = word[i] - 'a';
		
		if(root->children[index] == NULL)
			return 0;

		root = root->children[index];	
	}
	if(root->isEndOfWord)
		return 1;
	return 0;	
}

void show_words(Trie *node, std::string word){
	char letter;
	std::string before;
	
	if(node->isEndOfWord)
			std::cout<<word<<std::endl;
	
	for(int i = 0;i<ALPHABET_SIZE;i++){
			letter = 'a'+i; 
			before = word;
		if(node->children[i]){
			word = word + letter;
			show_words(node->children[i],word);
			word = before;
		}
	}
}

int delete_node(Trie *node,std::string word,int level){
	int key;	
	
	key = word[level] - 'a';
		
	for(int i=0;i<ALPHABET_SIZE;i++){
			if(key == i && node->children[i]){
				level++;
				if(delete_node(node->children[i],word,level))
					node->children[i] = NULL;	
				break;
			}
			if(key < 0 && node->isEndOfWord && node->children[i]){
				node->isEndOfWord = false;
				return 0;
			}
	}
	if(key < 0 && node->isEndOfWord){
		delete node;
		return 1;	
	}
	else if(!node->isEndOfWord){
		for(int i = 0;i<ALPHABET_SIZE;i++){
			if(node->children[i])
				key = 100;
		}
		if(key != 100){
			delete node;
			return 1;
		}
		return 0;
	}
	return 0;
	}
