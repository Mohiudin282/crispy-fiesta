#include<iostream>
using namespace std;

class ArrayQueue{
    private:
    int *q;
    int maxSize; 
    int currSize = 0;
    int front,back;
    public:
    ArrayQueue(int n){
        maxSize=n;
        currSize=0;
        front=0;
        back=-1;
        q = new int[maxSize];
    }
    ~ArrayQueue(){
        if(q!= NULL){
            delete []q;
            q = NULL;
        }
    }
    bool isFull(){
        if(currSize == maxSize){
            return true;
        }
        else{return false;}
    }
    bool isEmpty(){
        if(currSize == 0){
            return true;
        }
        else{return false;}
    }
    bool EnQueue(int val){
        if(!isFull()){
            back++;
            q[back]=val;
            currSize++;
            return true;
        }
        else{
            return false;
        }
    }
    bool DeQueue(int &temp){
        if(!isEmpty()){
            temp = q[front];
            front++;
            currSize--;
            return true;
        }
        else{
            return false;
        }
    }
    //Copy Constructor
    ArrayQueue(ArrayQueue &a){
        maxSize = a.maxSize;
        currSize = a.currSize;
        front = a.front;
        back = a.back;
        this->q = new int[maxSize];
        for(int i=0; i<maxSize; i++){
            this->q[i] = a.q[i];
        }
    }
    //Assignment Operator Overload
    ArrayQueue operator=(ArrayQueue &a){
        maxSize = a.maxSize;
        currSize = a.currSize;
        front = a.front;
        back = a.back;
        this->q = new int[maxSize];
        for(int i=0; i<maxSize; i++){
            this->q[i] = a.q[i];
        }
        return a;
    }
    void Display(){
        for(int i=0; i<currSize; i++){
            cout<<q[i];
        }
    }
};

int main(){
    ArrayQueue a(5);
    a.EnQueue(2);
    ArrayQueue q(5);
    q=a;
    int b;
    a.DeQueue(b);
    cout<<b<<endl;
    q.Display();
}