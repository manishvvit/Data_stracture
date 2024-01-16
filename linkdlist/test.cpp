#include <iostream>
using namespace std;
class dada{
  public:
  int d_amount;

};
class papa:public dada{
  public:
  int p_amount;

};
class mummy: public dada{
  public:
  int m_amount;

};
class shourya:public papa,public mummy{
  public:
  int mera_kamai;
  void print_kamai(){
    int total=p_amount+m_amount+papa::d_amount+mera_kamai;
    cout<<"meri total property hai "<<total<<endl;
    }
};
int main() {
  shourya s;
  
  s.papa::d_amount=12;
  s.p_amount=12;
  s.m_amount=17;
  s.mera_kamai=12;
  s.print_kamai();
  return 0;
}