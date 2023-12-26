#include<iostream>
using namespace std;

int SecondLargest(int *arr, int n){
    int largest = arr[0];
    int sLargest = -1;
    for(int i = 1; i<n; i++){
        if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > sLargest){
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int main(){
    int arr[] = {34,56,99,65,89,100};
    int x = SecondLargest(arr, 6);
    cout<<x;
}