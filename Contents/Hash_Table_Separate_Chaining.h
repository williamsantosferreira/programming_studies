//Hash Table - Separate Chaining
#include <iostream>

#define MAX 10

struct Array{
     int key;
     Array* next;
};

class Hash_Table{
    private:
    
    Array table[MAX];
    
    public:
    
    Hash_Table(int MAX){
       for(int i = 0; i < MAX; i++){
           table[i].next = NULL;
           table[i].key = 0;
    }}
    
    int hash_function(int key){
        int hash_value;
        
        hash_value = key % MAX;
        
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
    
        for(int i = 0; i < MAX; i++){
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
    
};
