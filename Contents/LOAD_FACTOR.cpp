//LOAD FACTOR AND REHASHING
#include <iostream>

#define DEFAULT_LF 0.75
#define MAX 1000

struct Array{
     int key;
     Array* next;
     
};

class Hash_Table{
    private:
    	
    Array* table;
    int size;
    float LOAD_FACTOR;
    int n; //number of elements
    
    public:
    
    Hash_Table(int size){
    	this->size = size;
    	n = 0;
    	
    	table = new Array[size];
    	
       for(int i = 0; i < size; i++){
           table[i].key = NULL;
           table[i].next = 0;
    }}
    
    int hash_function(int key){
        int hash_value;
        
        hash_value = key % size;
        
        return hash_value;
    }
    
    void colision (int key, int index){
       Array* temp;
       Array* temp2;
    
       temp = &table[index];
    
       while(temp != NULL){
          temp2 = temp;
          temp = temp->next;
    }
      temp = new Array;
      temp->key = key;
      temp->next = NULL;
    
      temp2->next = temp;
    }
    
    void new_element(int key){
       int index;
       
       index = hash_function(key);
    
       if(table[index].key != 0) //that is a colision
           colision(key,index);
       else
         table[index].key = key;
        
        LOAD_FACTOR = (float)n/size;
    }
    
    void increase_n(){
    	n = n+1;
	}
    
    
    Array* search(int key){
        int index;
        Array* temp;
        
        index = hash_function(key);
        
        if(table[index].key == key)
            return temp = &table[index];
        else if(table[index].key == 0)
           return NULL;
        else if(table[index].next != NULL){
            temp = table[index].next;
            while((temp != NULL) && (temp->key != key))
               temp = temp->next;
            if(temp == NULL)
              return NULL;
            else
              return temp;
        }
       
    }
    
    int delete_element(int key){
        //The idea here is simple but I won't implement in this code
        /*
        You search for the key in the HASH TABLE.
        1. If this element is at a position in HASH_TABLE you need to see if the next is point to NULL or not.
         1.1 If the next is point to NULL, you just delete the key
         1.2 If the next isn't point to NULL, you need to reajust the chaining
        2. If this element is at a position in one SEPARATE CHAINING you need to be more careful
        3. And maybe, you won't find any element with this key
        */
    }
    
    
    void print(){
        Array* temp;
    
        for(int i = 0; i < size; i++){
            std::cout<<i<<" --> ";
            if(table[i].key != 0)
              std::cout<<table[i].key<<" ";
            else
             std::cout<<"There is no element at this position";
            
            temp = table[i].next;
            
            while(temp != NULL){
                std::cout<<temp->key<<" ";
                temp = temp->next;
            }
            
            std::cout<<std::endl;
        
        }
    }
    
    float verify_LF(){
    	return LOAD_FACTOR;
	}
	
	void rehashing(){
		int new_size = 2*size;
		Array* temp;
		if(new_size > MAX)
			std::cout<<"The hash table can't be rehashing. It's reach its limit!"<<std::endl;
		else{
			int array[n], j = 0;
			
		    for(int i = 0; i < size; i++){
            	if(table[i].key != 0){
            		array[j] = table[i].key;
            		j++;
				}
            	temp = table[i].next;
            
            	while(temp != NULL){
                	array[j] = temp->key;
                	j++;
                	temp = temp->next;
            }
		
			}
			delete table;
			table = new Array[new_size];
			size = new_size;
			
			for(int i = 0; i < n; i++)
				new_element(array[i]);
		}
		
	}
    
};

int main(){
	Hash_Table hash(10);
	int array[] = {11,12,13,14,15,16,17,18};
	float LF;
	
	for(int i = 0; i < 8; i++){
		hash.increase_n();
		hash.new_element(array[i]);		
}
	LF = hash.verify_LF();
	
	if(LF > DEFAULT_LF){
		std::cout<<"LOAD FACTOR = "<<LF<<"\nREHASHING!!!"<<std::endl;
		
		hash.rehashing();
		hash.print();
		
		LF = hash.verify_LF();
		std::cout<<"NEW LOAD FACTOR = "<<LF<<std::endl;	
	}
	else
		std::cout<<"LOAD FACTOR = "<<LF<<std::endl;
    
    
	
	
	
	return 0;
}
