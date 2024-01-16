#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,2,3,4,4};
    //hashing 1.array hashing 2.mapping unorderedmap or map
    //hashing array
    //1. pre storing'
    //int hash[4+1]={0};
    map<int,int> mpp;
    for(int i=0;i<6;i++){
        mpp[arr[i]]++;
    }
    for(auto it=mpp.begin();it!=mpp.end();it++){
        //cout<<it->first<<" "<<it->second<<endl;
        if(it->second>=2) cout<<it->first<<endl;
        
    }
    return 0;
}