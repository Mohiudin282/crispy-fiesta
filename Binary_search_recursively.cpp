#include<iostream>
using namespace std;

bool binarySearch(int *arr, int start, int end, int val){
    int mid = (start + end)/2;
    if(arr[mid] == val){
        return true;
    }
    else if(arr[mid] > val && start <= end){
        return binarySearch(arr, start, mid - 1, val);
    }
    else if(arr[mid] < val && start <= end){
        return binarySearch(arr, mid + 1, end, val);
    }
    else{
        return false;
    }
}

int main(){
    int arr[] = {2,3,4,5,6,7,8};
    cout<<binarySearch(arr, 0, 6, 10);
}