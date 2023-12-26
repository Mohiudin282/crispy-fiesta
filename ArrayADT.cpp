#include <iostream>
using namespace std;
class Array
{
public:
    int currsize, maxsize;
    int *ptr;
    Array(int m)
    {
        maxsize = m;
        currsize = 0;
        ptr = new int[m];
    }
    ~Array()
    {
        delete[] ptr;
    }
};

class ArrayADT{
    private:
    Array *arr;
    public:
    ArrayADT(){
        arr=nullptr;
    }

    void createArray(int x){
        arr=new Array(x);
    }

    ArrayADT(const ArrayADT &b){
        if(b.arr==nullptr){
            cout<<"First create an Array";
            return;
        }
        arr=new Array(b.arr->maxsize);
        arr->maxsize = b.arr->maxsize;
        arr->currsize = b.arr->currsize;
        arr->ptr = new int [b.arr->maxsize];
        for(int i=0; i<=b.arr->maxsize; i++){
            arr->ptr[i] = b.arr->ptr[i];
        }
    }

    bool equalitycheck(const ArrayADT &b){
        int i;
        for(i=0; arr->ptr[i]==b.arr->ptr[i] && i< b.arr->currsize; i++);
        if(i==b.arr->currsize){
            return true;
        }
        else{
            return false;
        }

    }

    //Equal operator overload.
    bool operator==(const ArrayADT &s){
        
        if(arr->maxsize==s.arr->maxsize && arr->currsize==s.arr->currsize && equalitycheck(s) && 1 ){
            return true;
        }
        else{
            return false;
        }
    }

    void insertval(int val){
        arr->ptr[arr->currsize] = val;
        arr->currsize++;
    }

    void setValue(int index,int value){
        arr->currsize++;
        int i=arr->currsize;
        for(i=arr->currsize; i>index ; i--){
            arr->ptr[i]=arr->ptr[i-1];
        }
        arr->ptr[i]=value;
    }

    void getValue(){
        for(int i=0; i<arr->currsize; i++){
            cout<<arr->ptr[i]<<" ";
        }
    }

    void deletevalue(int index){
        for(int i=index+1; i<=arr->currsize; i++){
            arr->ptr[i-1]=arr->ptr[i];
        }
        arr->currsize--;
    }

    /* int RemoveAllx(int value){
        int c=0;
        for(int i=0; i<=arr->currsize; i++){
            if(arr->ptr[i] == value){
                arr->ptr[i]=0;
                c++;
            }
        }
        return c;
    } */

    ~ArrayADT(){
        delete arr;
    }
};

int main(){
    ArrayADT a;
    a.createArray(6);
    a.insertval(24);
    a.insertval(12);
    a.insertval(19);
    a.insertval(45);
    a.insertval(67);
    a.deletevalue(2);
    //a.RemoveAllx(56);
    a.getValue();
}