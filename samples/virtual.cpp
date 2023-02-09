#include<iostream>
using namespace std;
class base{
public:
   virtual void func(){
      cout<<"I am base function\n";
   }
};
class derived:public base{
public:
   void func(){
      cout<<"I am derived function\n";
   }
};
int main(){
   base b;
   derived d;
   derived *d1=new derived();
   d.func();
   d1->func();
   delete d1;
   base *b1=new derived();
   b1->func();
   base *b2=new base();
   b2->func();
   cout<<"The sizeof base is "<<sizeof(b)<<endl;
   cout<<"The sizeof derived is "<<sizeof(d)<<endl;
   cout<<"The sizeof derived d1 is "<<sizeof(*d1)<<endl;
   return 0;
}
