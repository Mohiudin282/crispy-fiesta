#include<iostream>
using namespace std;

void InsertionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int j=i;

        while(j>0 && a[j-1]>a[j]){ 
            int temp;
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;

            j--;
        }
    }
}

int main(){
    int arr[]={21,90,34,67,5};
    InsertionSort(arr,5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    
}