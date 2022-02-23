#include<iostream>

int lowest_integer(int* v,int n);

int main()
{
    int vec[]={1,3,-2};
    int n = sizeof(vec)/sizeof(int);
    
    std::cout<<lowest_integer(vec,n);

    return 0;
}

int lowest_integer(int* v, int n){
    int table[n+1]={0};
    for(int i = 0; i < n; i++){
        if(v[i]>0 && v[i]<=n){
            table[v[i]] = table[v[i]]+1;
        }
    }
    int i = 0;
    for(i = 1; i <=n; i++){
        if(table[i] == 0)
            return i;
    }
    return i;

}