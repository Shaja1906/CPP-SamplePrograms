#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Program to understand lambda functions
int main(){
   int nLenght=10;
   int nCount=11;
   vector<int> arr={1,2,3,4,5};
   /*The below code causes compilation error
   [](){
      cout<<"The value of nLength and nCount is "<<nLenght<<" and "<<nCount<<endl;
   }*/
   //Capture all external values by value
   [=](){
      cout<<"Capture by val::The value of nLength and nCount is "<<nLenght<<" and "<<nCount<<endl;
      /*The below commented code causes compilation error
       * as the external values are only captured by value.
      nLenght=11;
      nCount=12;*/
   }();
   [&](){
      cout<<"Capture by ref::The value of nLength and nCount is "<<nLenght<<" and "<<nCount<<endl;
      nLenght=11;
      nCount=12;
   }();
   cout<<"The modified values are "<<nLenght<<" and "<<nCount<<endl;
   [nLenght,&nCount](){
      cout<<"Capture by ref::The value of nLength and nCount is "<<nLenght<<" and "<<nCount<<endl;
      /*The below code will cause compilation err
      nLenght=15;*/
      nCount=15;
   }();
   cout<<"The modified values are "<<nLenght<<" and "<<nCount<<endl;
   for_each(arr.begin(),arr.end(),[](int nVal){
         ++nVal;
         cout<<nVal<<"/t";
   });
   return 0;
}
