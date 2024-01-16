#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maximum(int arr[],int size){
    //sorting 
    sort(arr,arr+size);
    return arr[size-1];
}
int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int max=maximum(arr,size);
    cout<<max<<endl;
    return 0;
}