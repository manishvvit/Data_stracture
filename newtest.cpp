#include <iostream>
#include<iomanip>
using namespace std;
void print();
class student{
  public:
  string name;
  int roll;
  char section;
  student(){
    cout<<"enter your name "<<endl;
    cin>>name;
    cout<<"enter your roll "<<endl;
    cin>>roll;
    cout<<"enter your section "<<endl;
    cin>>section;
  }

};
int main() {
  int number;
  cout<<"enter number of student"<<endl;
  cin>>number;
  student s[number];
  cout<<"NAME"<<left<<setw(10)<<"ROLL"<<left<<setw(10)<<"SECTION"<<endl;
  for(int i=0;i<number;i++){
    cout<<s[i].name<<left<<setw(10)<<s[i].roll<<left<<setw(10)<<s[i].section<<endl;
  }
return 0;
}