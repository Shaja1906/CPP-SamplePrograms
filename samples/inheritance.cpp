#include<iostream>
using namespace std;
class base{
   public:
      int i;
   private:
      char c;
   protected:
      float f;
};
class derived1:public base{
   derived1(){
      base::i=10;
      //base::c='a'; compilation error
      base::f=10.0;
   }
};
class derived2:protected base{
   derived2(){
      base::i=10;
      //base::c='a'; compilation error
      base::f=10.0;
   }
};
class derived3:private base{
   derived3(){
      base::i=10;
      //base::c='a'; compilation error
      base::f=10.0;
   }
};
int main(){
   return 0;
}
