#include<iostream>
using namespace std;

void BubbleSort(int *arr, int n){
    if(n<1){
        return;
    }
    for(int j=0; j<n-1; j++){
        if(arr[j]>arr[j+1]){
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    BubbleSort(arr, n-1);
}

int main(){
    int arr[]={2,56,43,67};
    BubbleSort(arr, 4);
    for(int i=0; i<4;i++){
        cout<<arr[i]<<" ";
    }
}