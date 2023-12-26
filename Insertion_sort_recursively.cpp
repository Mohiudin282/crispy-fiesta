#include <iostream>
using namespace std;

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int *arr, int start, int end)
{
    if (start == end )
        return;
    int j = start;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j - 1], arr[j]);
        j--;
    }
    InsertionSort(arr, start+1, end);
}

int main(){
    int arr[]={2,56,43,67,56,76,89,90};
    int n= sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, 0, n);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}