#include<iostream>
using namespace std;

void bubblesort(int a[], int n){
    for(int i=n-1 ; i>0 ;i--){
        for(int j=0; j<i ; j++){
            if(a[j]>a[j+1]){
                int temp;
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
   
}

int main(){
    int arr[]={5,5,3,2,1};
    bubblesort(arr,5);
      for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }
}