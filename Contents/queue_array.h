//Queue Array Implementation
#include <iostream>

class Queue{
   private:
      int front; //indicate the first element 
      int rear; //indicate the last element
      int size = 100;
      int node[100];
          
   public:
   
    
       Queue(){
          front = 0;
          rear = -1;
     }
      
      int enqueue(int val){
         if(rear < size){
           rear++;
           node[rear] = val;
           return 1;
        }
        else
          return 0;
      }
    
     int dequeue(){
        if(rear >= front){
             front++;
             return 1;
        } 
        else
            return 0;
        
    }
    int front_element(){
         return front;
    }
    
    int rear_element(){
         return rear;
    }
    
    void list(){
         if(rear>=front){
            for(int i = front; i <= rear; i++){
               std::cout<<node[i]<<std::endl;
            }}
         else
           std::cout<<"The Queue is empty"<<std::endl;
        
    }
    
};
