#include<iostream>
using namespace std;

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int PartitionIndex(int *arr, int low, int high){
    int i=low;
    int j=high;
    int pivot = arr[low];
    while(i < j){
    /* reverse the inequality sign in these both 
    while loops just the signs which are compared with pivot */
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(int *arr, int low, int high){
    if(low < high){
        int pIndex=PartitionIndex(arr, low, high);
        QuickSort(arr, low, pIndex - 1);
        QuickSort(arr, pIndex + 1, high);
    }
}

int main(){
    int a[] = {34,69,86,45,90,32,14};
    int size = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, size-1);
    for(int i=0; i < size; i++){
        cout<<a[i]<<" ";
    }
}