#include<iostream>
/*Without using vector class */
using namespace std;

// Merge two hypothetical Arrays

void merge(int *arr, int low, int mid, int high){
    int left=low;
    int right=mid+1;
    int size=high-low+1;
    int *ptr= new int[size];
    int k=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            ptr[k]=arr[left];
            left++; k++;
        }
        else{
            ptr[k]=arr[right];
            right++; k++;
        }
    }

    while(left<=mid){
        ptr[k]=arr[left];
        left++; k++;
    }
    while(right<=high){
        ptr[k]=arr[right];
        right++; k++;
    }
    /*Move values from temporary to original array*/
    for(int i=low; i<=high; i++){
        arr[i]=ptr[i-low];
    }

    delete []ptr;
    ptr=NULL;
}

//Recursion

void MergeSort(int *arr, int low, int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int arr[]={51,92,34,26,68,23,51,70};
    MergeSort(arr, 0, 7);
    for(int i=0; i<=7; i++){
        cout<<arr[i]<<" ";
    }
}