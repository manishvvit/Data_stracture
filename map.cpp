#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{9,10,10,16,17};
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    //print mpp
    for(auto it=mpp.begin();it!=mpp.end();it++){
        cout<<it->first<<" ";
    }
    cout<<mpp.size()<<endl;
}