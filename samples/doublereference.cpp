#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int i=10;
   int j=18;
   int &r=i;
   int &c=i;
   // int &d=NULL; compilation error;
   i=12;
   cout<<"Changing the value of i will also change the value of r "<<r<<endl;
   c=j;
   cout<<"The value of c and i is "<<c<<" and "<<i<<endl;
   j=14;
   cout<<"The value of c,i and j is "<<c<<","<<i<<" and "<<j<<endl;
   cout<<"The address of i "<<&i<<endl;
   cout<<"The address of j "<<&j<<endl;
   cout<<"The address of r "<<&r<<endl;
   cout<<"The address of c "<<&c<<endl;
   //double reference:
   int &&e=20;
   cout<<"The value of e is "<<e<<endl;
   cout<<"The address of e is "<<&e<<endl;
   e=100;
   cout<<"The value of e is "<<e<<endl;
   cout<<"The address of e is "<<&e<<endl;
   // int &f; compilation error. Reference must be initialized at declaration
   return 0;
}
