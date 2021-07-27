#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

struct Node{
	int age;
	Node *next;
};

class Linked_List{
	private:
		Node *start;
		std::ofstream write;
		std::ifstream read;
		std::string arq;
	public:
		Linked_List(std::string file){
			start = NULL;
			arq = file + ".txt";
		}
		
		int open_write(){
			write.open(arq.c_str());
			if(write.good())
				return 1;
			return 0;
		}
		
		int open_read(){
			read.open(arq.c_str());
			if(read.good())
				return 1;
			return 0;
		}
	
	void read_arq(){
		if(open_read()){
			Node *temp,*temp2;
			temp = new Node;
			temp->next = NULL;
			start = temp;
			while(read>>temp->age){
				temp2 = temp;
				temp = new Node;
				temp->next = NULL;
				temp2->next = temp;
			}
			delete temp;
			temp2->next = NULL;
		}
	}
	
	void new_node(){
			Node *temp,*temp2;
				
				temp = new Node;
				
				std::cout<<"Write the age: ";
					std::cin>>temp->age;
				temp->next = NULL;
			if(start == NULL)
				start = temp;
			else{
				temp2 = start;
				while(temp2->next != NULL){
					temp2 = temp2->next;
			}
				temp2->next = temp;
				gravar();
			}}
		
	void show_node(){
		Node *temp;
		if(start == NULL)
			std::cout<<"There's nothing to show!"<<std::endl;
		else{
			temp = start;
			while(temp->next != NULL){
				std::cout<<temp->age<<std::endl;
				temp = temp->next;
			}
			std::cout<<temp->age<<std::endl;
		}
	}
	
	void gravar(){
		Node *temp;
		if(open_write()){
			temp = start;
			if(start == NULL)
				std::cout<<"Any nodes to save!"<<std::endl;
			else{
				while(temp->next != NULL){
					write<<temp->age<<std::endl;
					temp = temp->next;
				}
				write<<temp->age<<std::endl;
				write.close();
			}
		}
	}
};

int main(){
	std::string arq = "teste";
	Linked_List list(arq);
	
	int escolha = 1;
	
	while(escolha != 4){
		system("cls");
		std::cout<<"1. New node\n2. Show all nodes\n3. Read file\n4. Exit\nChoose: ";
			std::cin>>escolha;
		switch(escolha){
			case 1:
					list.new_node();
					list.gravar();
					break;
			case 2:
					list.show_node();
					system("pause");
					break;
			case 3:
					list.read_arq();
					break;
			case 4:
					std::cout<<"Thanks for using my program!"<<std::endl;
					break;
			default:
					std::cout<<"Invalid choose!"<<std::endl;
					system("pause");
					break;
		}
			
	}
	

	return 0;	
}
