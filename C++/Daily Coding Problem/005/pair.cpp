#include <iostream>

struct Pair{
    int a;
    int b;
};

Pair cons(int a, int b);
int car(Pair p);
int cdr(Pair p);

int main(){
    Pair p;

    std::cout<<car(cons(3,2))<<" "<<cdr(cons(3,2));

    return 0;
}
Pair cons(int a, int b){
    Pair p;
    p.a = a;
    p.b = b;
    return p;
}
int car(Pair p){
    return p.a;
}
int cdr(Pair p){
    return p.b;
}