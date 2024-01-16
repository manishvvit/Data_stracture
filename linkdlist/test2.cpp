#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class B{
    public:
    int a;
    int b;
    public:
    int add(){
        return a+b;
    }
    void operator+(B &obj){
    int value=this->a;
    int value2=obj.a;
    cout<<"Result is "<<value-value2<<endl;
        
    }
    
};

int main(){
    B ob1,ob2;
    ob1.a=4;
    ob2.b=7;
    ob1+ob2;
}