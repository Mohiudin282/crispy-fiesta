#include<iostream>
using namespace std;

int lowerBound(int *arr, int n, int x){
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int *arr, int n, int x){
    int last = -1;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] <= x){
            last = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}
void first_and_last_occourence(int *arr, int n, int x){
    int z = lowerBound(arr, n - 1, x);
    int y = upperBound(arr, n - 1, x);
    cout<<z<<","<<y;
}


int main(){
    int arr[] = {2,3,5,5,5,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    first_and_last_occourence(arr, size, 5);
}