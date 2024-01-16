#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a{1,2,3,4,5,2};
    vector<int> arr;
    for(int i=0;i<a.size();i++){
        arr.push_back(a[i]);
    }
    sort(arr.begin(),arr.end());
for(int i=0;i<a.size();i++){
    if(arr[i]!=a[i]){
    cout<<"not"<<endl;
    break;
    }
    else{
        cout<<"sorted"<<endl;
    }
}
    return 0;
}