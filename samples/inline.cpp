#include<iostream>
using namespace std;
inline int func(char a){
   return 10;
};
int main(){
   int local=100;
   int clocal=1;
   int a=func('a');
   int b=func('b');
   int c=func('c');
   return 0;
}
