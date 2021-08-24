#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

struct Node{
	int value;
	Node *next;
};

class Linked_List{
	private:
		Node *start;
	public:
		Linked_List(){
			start = NULL;
		}
		void new_node(int value){
			Node *temp,*temp2;
				
				temp = new Node;
				temp->value = value;
				temp->next = NULL;
				
			if(start == NULL)
				start = temp;
			else{
				temp2 = start;
				while(temp2->next != NULL){
					temp2 = temp2->next;
			}
				temp2->next = temp;
			}}
		
		void show_node(){
			Node *temp;
			if(start == NULL)
				std::cout<<"There's nothing to show!"<<std::endl;
			else{
				temp = start;
				while(temp!= NULL){
					std::cout<<temp->value<<" ";
					temp = temp->next;
				}
				std::cout<<std::endl;
			}
		}
		int len(){
			Node* temp;
			int length = 0;
			
			temp = start;
			while(temp != NULL){
				temp = temp->next;
				length++;
			}
			return length;
		}
		
		Node* search(int value){
			Node* temp;
			
			temp = start;
			
			while(temp != NULL){
				if(temp->value == value)
					return temp;
				temp = temp->next;
			}
			return NULL;
		}
		
		void delete_node(int value){
			Node* temp;
			
			if(this->search(value) != NULL){
				if(start->value == value){
					if(start->next == NULL){
						delete start;
						start = NULL;
					}
					else{
						temp = start->next;
						delete start;
						start = temp;
					}
				}
				else{
					temp = start;
					while(temp->next->value != value)
						temp = temp->next;
					if(temp->next->next == NULL){
						delete temp->next;
						temp->next = NULL;
					}
					else{
						Node* temp1;
						temp1 = temp->next;
						temp->next = temp->next->next;
						delete temp1;
					}
					
				}
			}
				
		}
		
};

int main(){
	Linked_List list;
	Node* temp;
	
	list.new_node(10);
	list.new_node(11);
	list.new_node(12);
	
	list.show_node();
	
	list.delete_node(12);
	
	list.show_node();
	
	
	return 0;	
}
