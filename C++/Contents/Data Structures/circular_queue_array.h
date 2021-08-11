#include <iostream>

class Queue{
  private:

    int front = -1;
    int rear = -1;
    int data[5];
    int size = 5;
 
 public:
    
    int enqueue(int d){
      if(front == -1 && rear == -1){
           front = 0;
           rear = 0;
        
           data[rear] = d;
           return 1;
      }
    
      if(rear == size-1 && front == 0)
         return 0;
      else if (rear == front-1)
         return 0;
      else{
        rear = (rear+1)%size;
        data[rear] = d;
        
        return 1;
      }
   }
    
    int dequeue(){
         if(front == -1)
           return 0;
        else if(front == rear){
           front = rear = -1;
           return 1;
        }
        else if(front == size-1){
           front = 0;
           return 1;
        
        }      
        else{
           front++;
           return 1;
        }
    }
   int list(){
        if(front == -1)
          return 0;
        else{
            int i = front;
            while(i != rear ){
              std::cout<<data[i]<<std::endl;
              i = (i+1)%size;
            }
              std::cout<<data[i]<<std::endl;
            return 1;
        }
        
    }
    
   int front_value(){
       return front;
   }

   int rear_value(){
      return rear;
   }   
};
