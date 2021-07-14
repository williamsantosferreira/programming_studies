//This code is implementing a HASH_TABLE - Linear Probing, Quadratic Probing, Double Hashing
#include <iostream>

#define MAX 10

struct Array{
	int key;
	int situation; //0 --> empty, 1 --> full, -1 --> deleted
};

class Hash_Table{
	private:
		Array table[MAX];
	public:	
	    Hash_table(){
	    	for(int i = 0; i < MAX; i++){
	    		table[i].key = 0;
	    		table[i].situation = 0;
	    }
	    		
		}
		
		int hash_function(int key){
			return key%MAX;
		}
		
		int linear_probing(int index,int key){ 
			int i = 0,linear;
			
			 if(table[index].key == key)					    
				return -2; //same key
			do{
					i++;
					
					linear = (index + i)%MAX;
							
					if(table[linear].situation != 1){
					    table[linear].key = key;
					    table[linear].situation = 1;
						return linear;
					}			
					else if(table[linear].key == key)
						return -2;
						
				}while(linear != index);
				
				return -1; // full
		}
		
		int quadratic_probing(int index, int key){
			int i = 1, quadratic = -1;
		          if(table[index].key == key)
		          		return -2;
			while(quadratic != index){
				quadratic = (index + i*i)%MAX;
				if(table[quadratic].situation != 1){
					table[quadratic].key = key;
					table[quadratic].situation = 1;
					return quadratic;
				}
				else if(table[quadratic].key == key)
					return -2;
				
				i++;
			}
			return -1;
		}
		
		int hash2_function(int key){
		    int value = (7 -(key%7));
			return value; //7 is the first prime below than MAX
		}
		int double_hashing(int key){
			int i = 1,index;
			
			index = hash_function(key);
			if(table[index].key == key)
				return -2;
			index = -1;
			
			while(hash_function(key) != index){
				index = (hash_function(key) +i*hash2_function(key))%MAX;
				
				if(table[index].situation != 1){
					table[index].key = key;
					table[index].situation = 1;
					return index;
				}
				else if(table[index].key == key)
					return -2;
			i++;
			}
			return -1;
			
		}
		
		int add_element(int key,int opt = 0){ // return index, if index > 0 then we added a new operation, index = -1 -> FULL, index = -2 -> Same key
			//opt = 0 -> linear
			//opt = 1 -> quadratic
			//opt = 2 -> double hashing
			
			int index;
			int i = 0;
			
			index = hash_function(key);
			
			if(table[index].situation != 1){
				table[index].key = key;
			    table[index].situation = 1;
			    return index;
			}
			else if(opt == 0)
				return linear_probing(index,key);
			else if(opt == 1)
				return quadratic_probing(index,key);
			else
				return double_hashing(key);
		}
		
		void list(){
			for(int i = 0; i< MAX; i++){
			     std::cout<<i<<"("<<table[i].situation<<") --> ";
			     if(table[i].situation == 1)
			     	std::cout<<table[i].key;
			     	
				std::cout<<std::endl;
			}
		}
		
		int search_linear(int key){ //return the index or -1 if it doesn't find any key in the hash table
		      int index, i = 1,linear = -1;
		      
		      index = hash_function(key);
		      if(table[index].key == key)
		      	return index;
		      else if(table[index].situation != 1)
		      	return -1;
		      else{
		      	 while(linear != index){
		      	 	linear = (index + i)%MAX;
		      	 	
		      	 	if(table[linear].key == key)
		      	 		return linear;
		      	 	else if(table[linear].situation == 0)
		      	 		return -1;
				   i++;
				   }
		      	return -1;
			  }
	}
		int search_quadratic(int key){
			int index, i = 1, quadratic = -1;
			
			index = hash_function(key);
			if(table[index].key == key)
				return index;
			else if(table[index].situation != 1)
				return -1;
			else{
				while(quadratic != index){
					quadratic = (index + i*i)%MAX;
					
					if(table[quadratic].key == key)
						return quadratic;
					else if(table[quadratic].situation == 0)
						return -1;
				i++;
				}
				return -1;
			}
		}
		int search_double(int key){
			int index, i = 1, double_hashing = -1;
			
			index = hash_function(key);
			if(table[index].key == key)
				return index;
			else if(table[index].situation != 1)
				return -1;
			else{
				while(double_hashing != index){
					
					double_hashing = (index + i*hash2_function(key))%MAX;
					
					if(table[double_hashing].key == key)
						return double_hashing;
					else if(table[double_hashing].situation == 0)
						return -1;
					i++;
				}
				return -1;
			}
		}
		
		int delete_(int index){
			if(index == -1)
				return -1;
			else{
				table[index].key = 0;
				table[index].situation = -1;
				return 1;
			}
		}
		
		int delete_linear(int key){
			int index;
			
			index = search_linear(key);
			
			return delete_(index);
		}
		
		int delete_quadratic(int key){
			int index;
			
			index = search_quadratic(key);
			
			return delete_(index);
		}
		
		int delete_double(int key){
			int index;
			
			index = search_double(key);
			
			return delete_(index);
		}
		
		void clear(){
			for(int i = 0; i < MAX; i++){
				table[i].key = 0;
				table[i].situation = 0;
			}
		}
			
};
