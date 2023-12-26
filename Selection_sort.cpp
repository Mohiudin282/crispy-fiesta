#include<iostream>
using namespace std;

void selectionsort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i; j<n;j++){
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        int temp;
        temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
    }
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int arr[]={6,8,3,9,12,5,45,32,89};
    selectionsort(arr,9);
    
}