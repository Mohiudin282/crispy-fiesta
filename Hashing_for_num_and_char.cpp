#include<iostream>
using namespace std;

// Hashing For Numbers

/* int main(){

    int arr[5]={2,3,2,7,3};

    int hash[8]={0};
    for(int i=0; i<5; i++){
        hash[arr[i]]++;
    }
    int q,n;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>n;
        cout<<hash[n]<<endl;
    }
} */

// Hashing For Characters

int main(){
    char arr[9]={'a','b','c','d','b','a'};

    int hash[26]={0};
    for(int i=0; i<9; i++){
        hash[arr[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
}