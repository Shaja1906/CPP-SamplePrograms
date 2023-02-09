#include<iostream>
using namespace std;
template <class T>
class smartptr
{
   private:
      T* ptr;
   public:
      smartptr(T* lPtr)
      {
         this->ptr=lPtr;
      }
      ~smartptr()
      {
         if( NULL != this->ptr )
         {
            cout << "Deleting the ptr\n";
            delete this->ptr;
            this->ptr=NULL;
         }
      }
      T& operator * ()
      {
         return *ptr;
      }
      smartptr* operator -> ()
      {
         return this;
      }
};
template <class X>
class refptr
{
   private:
      int nCount;
      X* ptr;
   public:
      refptr(X* lPtr)
      {
         cout<<"refptr::Constructor\n";
         this->ptr=lPtr;
         nCount=1;
      }
      refptr()
      {
         cout<<"refptr::Constructor\n";
         this->ptr=NULL;
         nCount=0;
      }
      refptr(const refptr& oref)
      {
         cout<<"refptr::Copy Constructor\n";
         this->ptr=oref.ptr;
         this->nCount=oref.nCount;
         this->nCount++;
         cout<<"Count value after incrementing "<<nCount<<endl;
      }
      refptr& operator = (const refptr& rref)
      {
         cout<<"refptr::Assignment Operator\n";
         if( this!=&rref )
         {
            this->ptr=rref.ptr;
            this->nCount=rref.nCount;
            this->nCount++;
            cout<<"Count value after incrementing "<<nCount<<endl;
         }
         return *this;
      }
      ~refptr()
      {
         cout<<"refptr::Destructor\n";
         nCount--;
         cout<<"Count value after decrementing "<<nCount<<endl;
         if( 0 == nCount )
         {
            if( NULL != this->ptr )
            {
               cout << "Deleting the refptr\n";
               delete this->ptr;
               this->ptr=NULL;
            }
         }
      }
      int getCount()
      {
         return nCount;
      }
      void printptr(){
         cout<<"The value of ptr is "<<*ptr<<endl;
      }
      refptr& operator* ()
      {
         return *this;
      }
      refptr* operator -> ()
      {
         return this;
      }
};
int main()
{
   int *p=new int(10);
   {
      smartptr<int> sPtr(p);
      cout<<"The value of smartptr is "<<*sPtr<<endl;
   }
   cout<<p<<endl;
   
   int* i=new int(11);
   refptr<int> rPtr(i);
   //int nCnt=rPtr->getCount();
   {
      refptr<int> rptr1=rPtr;
   }
   {
      refptr<int> rptr2;
      rptr2=rPtr;
   }
   rPtr->printptr();

   //cout << "The count of reference pointer is "<<nCnt<<endl;
   return 0;
}
