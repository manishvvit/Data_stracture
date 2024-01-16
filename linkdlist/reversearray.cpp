#include<bits/stdc++.h>
using namespace std;
vector<int> rev(vector<int>& arr,int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;

    }
    return arr;

}
int main(){
vector<int> v={1,2,3,4,5};
vector<int> op=rev(v,3,4);
for(int i=0;i<5;i++) cout<<op[i]<<" ";


    return 0;
}