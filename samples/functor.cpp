#if defined(LINUX) || defined(CYGWIN_NT)
   #include <iostream>
   using namespace std;
#elif defined(SUNOS) || defined( HP_UX ) || defined(AIX)
   #include <iostream.h>   // cout
#endif
#include <vector>          // vector
#include <bits/stdc++.h>   // sort
class sortalgo
{
      public:
         bool operator()(const int& a, const int& b)
         {
            cout<<"int sort"<<endl;
            return a<b;
         }
         bool operator()(const char& a, const char& b)
         {
            cout<<"char sort"<<endl;
            return a<b;
         }
};
int main()
{
   vector<int> v={1,3,2,6,9,7};
   vector<char> c={'m','u','r','u','g','e','s','a','n',' ','o','p','e','n','s','s','l'};
   sort(v.begin(),v.end(),sortalgo());
   for(int i=0;(int)v.size()>i;++i)
   {
      cout<<v[i]<<endl;
   }
   sort(c.begin(),c.end(),sortalgo());
   for(int i=0;(int)c.size()>i;++i)
   {
      cout<<c[i]<<endl;
   }
   return 0;
}
