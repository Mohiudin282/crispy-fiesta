#include<iostream>
using namespace std;

int Max(int *arr, int n){
    int end = n - 1;
    int start = 0;
    int max = arr[0];
    while(start <= end){
        if(arr[start] > max){
            max = arr[start];
            start++;
        }
        else
        start++;
    }
    return max;
}

int main(){
    int arr[] = {34,56,99,65,89,100};
    int x = Max(arr, 6);
    cout<<x;
}