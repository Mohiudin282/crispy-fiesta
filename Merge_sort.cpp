#include<iostream>
/*With vector class*/
#include<vector>
using namespace std;

// Merge two hypothetical Arrays

void merge(int *arr, int low, int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
    }
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
    int arr[]={51,92,34,26,68};
    MergeSort(arr, 0, 4);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}