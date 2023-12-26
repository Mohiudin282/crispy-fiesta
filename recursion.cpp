#include<iostream>
using namespace std;
int minArr(int arr[], int n){
    if(n==0){
        return arr[0];
    }
    else{
        if(arr[n]<minArr(arr,n-1)){
            return arr[n];
        }
        else{
            return arr[n-1];
        }
    }
}
int main(){
    int arr[4]={-1,5,3,6};
    int n=minArr(arr,3);
    cout<<n;
}