#include <iostream>

struct Node{
    int data;
    Node* next;
};

class Queue{
    private:
      Node* front;
      Node* rear;
    public:
      Queue(){
          front = NULL;
          rear = NULL;
      }
    
     void enqueue(int d){
        if(front == NULL){
           front = new Node;
        
           front->data = d;
           front->next = NULL;
        
           rear = front;
        }
        else{
            Node* temp;
            
            temp = rear;
            
            rear = new Node;
            rear->data = d;
            rear->next = NULL;
            
            temp->next = rear;
        }
    }
    
    int dequeue(){
        if(front == NULL)
          return 0;
        else{
           Node* temp;
        
           temp = front;
           front = front->next;
        
            delete(temp);
            
          return 1;
        }
    }
    
    int list(){
        if(front == NULL)
          return 0;
        else{
           Node *temp;
           temp = front;
           while(temp != NULL){
                std::cout<<temp->data<<std::endl;
                temp = temp->next;
           }
        }
    }
    
    int front_value(){
        if(front != NULL)
         return front->data;
        else
         return 0;
    }
    
    int rear_value(){
        if(rear != NULL)
          return rear->data;
        else
          return 0;
    }

};
