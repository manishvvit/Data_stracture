#include<iostream>
using namespace std;
class Animal{
    public:
   virtual void display(){
        cout<<"Hey i am displaying in Animal"<<endl;
    }
   
};
class Animal2:public Animal{
    public:
    void display(){
        cout<<"Hey i am displaying in Animal2"<<endl;
    }

};
int main(){
    Animal *ptr;
    Animal2 b;
    ptr=&b;
    ptr->display();


   
   

    return 0;
}