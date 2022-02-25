#include <iostream>
#include <cstdint>

//XOR Linked List Node Struct
struct Node{
    int value; 
    Node* link; //XOR between PREVIOUS^NEXT
};


Node* XOR(Node* previous, Node* next){
    return (Node*)((uintptr_t)(previous) ^ (uintptr_t)(next)); //Return an address 
}
//First Node
Node* start;

//Traverse the linked list
Node* traverse(int i = 0){ //i = 0 show on the screen
    Node* current;
    Node* previous = NULL;
    Node* next;
    current = start;
    while(current != NULL){
        if(i == 0)
            std::cout<<current->value<<" --> ";
        next = XOR(previous,current->link); //For example, A --> B --> C, and current = B, next = A^(A^C) = A^A^C = 0^C = C
        previous = current;
        current = next;
    }
    return previous; //It helps me when I want to add a new node
}

void add(int value){
    Node* aux = new Node;

    aux->value = value;

    if(start == NULL){
        aux->link = NULL; //Previous = NULL and Next = NULL, so 0^0 = 0
        start = aux;
    }
    else{
        Node* p;
        p = traverse(1); //p = last node
        aux->link = XOR(p,NULL);
        p->link = XOR(p->link,aux); //For example, A-->B-->C, current = B. aux = C, so XOR(A^NULL,C) = A^C, previous = A and next = C.
    }
}

Node* find(int value){
    Node* current = start;
    Node* previous = NULL;
    Node* next;

    while(current != NULL){
        if(current->value == value)
            return current;
        next = XOR(previous,current->link);
        previous = current;
        current = next;
    }
    return NULL;
}

int main(){
    start = NULL;
    Node* aux;
    for(int i = 0; i < 5; i++)
        add(i);
    traverse();
    if((aux = find(5)) != NULL)
        std::cout<<"\n"<<aux->value;
    else   
        std::cout<<"\nThe value doesn't exist on the list!"<<std::endl;

    return 0;
}