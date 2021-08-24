#include <iostream>
#include <stdlib.h>

struct Node{
	int value;
	Node* next;
};

class Stack{
	private:
		Node* start;
		Node* Top;	
		
	public:
		Stack(){
			start = NULL;
			Top = NULL;
		}
		
		int isEmpty(){
			if(Top == NULL)
				return 1;
			return 0;
		}
		
		void push(int n){
			Node* temp;
			
			temp = new Node;
			
			temp->next = NULL;
			temp->value = n;
			
			if(start == NULL)
				start = temp;
			else{
				Node* temp1;
				
				temp1 = start;
				
				while(temp1->next != NULL)
					temp1 = temp1->next;
				temp1->next =temp;
			}	
			
			Top = temp;
		}
		
		int pop(){
			Node* temp;
		
			if(Top != start){
				temp = start;
				
				while(temp->next != Top)
					temp = temp->next;
				delete Top;
				temp->next = NULL;
				Top = temp;
			}	
			else if(Top == start){
				delete start;
				start = NULL;
				Top = NULL;
			}
			else
				return 0;
			
		return 1;
		}
		
		int top(){
				return Top->value;
		}
		
		void traverse(){
			Node* temp;
			
			temp = start;
		
			while(temp != NULL){
				std::cout<<temp->value<<" ";
				temp = temp->next;
			}
			std::cout<<std::endl;
		}
		
		int len(){
			int n = 0;
			Node* temp;
			
			temp = start;
			
			while(temp!=NULL){
				n++;
				temp = temp->next;
			}	
			return n;
		}
		
};
int main(){
	Stack s;
	int option = 1,value;
	
	while(option != 6){
		std::cout<<"STACK"<<std::endl;
		
		std::cout<<"1 - Push"<<std::endl<<"2 - Pop"<<std::endl<<"3 - Top"<<std::endl<<"4 - Traverse"<<std::endl<<"5 - Length"<<std::endl<<"6 - Exit"<<std::endl<<"Option: ";
		std::cin>>option;
		
		switch(option){
			case 1:
				system("cls");
				std::cout<<"STACK: PUSH"<<std::endl;
				std::cout<<"Write the value: "<<std::endl;
				std::cin>>value;
				
				s.push(value);
				
				break;
			case 2:
				system("cls");
				std::cout<<"STACK: POP"<<std::endl;
				
				if(s.pop())
					std::cout<<"Popped!"<<std::endl;
				else
					std::cout<<"Stack is empty!"<<std::endl; 
				system("pause");
				break;
			case 3:
				system("cls");
				std::cout<<"STACK: TOP"<<std::endl;
				
				if(!s.isEmpty())
					std::cout<<"Top: "<<s.top()<<std::endl;
				else
					std::cout<<"Stack is empty!"<<std::endl;
					
				system("pause");
				break;
			case 4:
				system("cls");
				std::cout<<"STACK: TRAVERSE"<<std::endl;
				
				if(!s.isEmpty())
					s.traverse();
				else
					std::cout<<"Stack is empty!"<<std::endl;
					
				system("pause");
				break;
			case 5:
				system("cls");
				std::cout<<"STACK: LENGHT"<<std::endl;
				
				std::cout<<"Stack lenght: "<<s.len()<<std::endl;
				
				system("pause");
				break;
			case 6:
				break;
			default:
				std::cout<<"You need to put a number between 1 and 6. Try again!"<<std::endl;
				system("pause");
		}
			system("cls");
	}


	return 0;
}
