//Circular Queue (Linked List Implementation)
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
    
    void enqueue(int val);
    
    int dequeue();
    
    int list();
    
};

void Queue::enqueue(int val){
   if(front == NULL){
       front = new Node;
       front->data = val;
       front->next = front;
       rear = front;
       
}
  else{
     rear->next = new Node;
     rear = rear->next;
    
     rear->data = val;
     rear->next = front;
}
}

int Queue::dequeue(){
       Node* temp;
    if(front == NULL)
       return 0;
    else if(front == rear){
       temp = front;
       front = NULL;
       rear = NULL;
    
       delete(temp);
       return 1;
    }
    else{
      temp = front;
      front = front->next;
    
      delete(temp);
    
      return 1;
    }
}

int Queue::list(){
     if(front == NULL)
       return 0;
    else{
       Node *temp;
        temp = front;
        
      while(temp != rear){
         std::cout<<temp->data<<std::endl;
         temp = temp->next;
    }
         std::cout<<temp->data<<std::endl;
      return 1;
    }
}