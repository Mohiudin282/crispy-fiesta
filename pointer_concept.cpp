#include<iostream>
using namespace std;
int* check(){
    int t,*p;
    t=100;
    p=&t;
    return &*p;
}
int main(){
    int *y=check();
    cout<<*y;
}