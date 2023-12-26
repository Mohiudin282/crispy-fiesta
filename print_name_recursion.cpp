#include<iostream>
using namespace std;

/* void print(int n){
    if(n==0){
        return;
    }
    else{
        print(n-1);
        cout<<"james"<<endl;
    }
}
int main(){
    print(5);
} */

// Print from 1-n

void print(int s, int e){
    if(s>e){
        return;
    }
    else{
        cout<<s<<endl;
        print(s+1,e);
    }
}
int main(){
    print(1,8);
}