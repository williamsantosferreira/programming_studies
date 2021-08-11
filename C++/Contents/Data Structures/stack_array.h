/*
Author: William Santos
Title: Stack's Basic Functions
W
Descritption: This code try to show up the basics functions of Stacks, they're:
push, pull, isEmpty, top.
First, I'm going to build the Stack using vector. 
*/

#include <iostream>
#include <vector>

#define MAX 1000

class Stack{
 private:
   std::vector<int> array; //First, I'm going to build an INT stack
 public:
   int push(int val){
      if(array.size() < MAX-1){
         array.push_back(val);  
         return 1;
      }
      return 0;
   }
   int pop(){
      if(array.size() > 0 ){
         array.pop_back();
         return 1;
       }
      else
         return 0;
   }
   int isEmpty(){
       if(array.size())
         return 0;
       else
         return 1;
   }
   int peek(){ //before use this function it's important to verify if our stack is empty
       return array.back();
   }

};
    