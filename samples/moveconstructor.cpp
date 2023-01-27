#include <iostream>
#include <vector>
using namespace std;
/* Build this program by disabling copy elison */
class Test
{
	public:
	int m_nCount;
   int* pLength;
	public:
	//Default constructor
	Test()
	{
	   cout<<"Test Default constructor"<<"\n";
	}
	//One argument constructor->conversion constructor
	Test(int nCount) : m_nCount(nCount),pLength(new int(nCount))
	{
	   cout<<"Test One argument constructor"<<"\n";
	}
	//Copy constructor
	Test(const Test& test)
	{
      cout<<"Test Copy constructor"<<"\n";
      this->m_nCount=test.m_nCount;
      //deep copying
      this->pLength=new int(this->m_nCount);
	}
	//Assignment operator
	Test& operator=(const Test& test)
	{
	   if(this!=&test)
	   {
		//delete the pointer in current object is needed
		//assign the value from rhs object to current object
		cout<<"Test Assignment operator if"<<"\n";
	   }
      else
      {
         cout<<"Test Assignment operator else"<<"\n";
      }
	   return *this;
	}
   //Move constructor
   Test(Test&& other) noexcept {
      cout<<"Test Move Constructor"<<endl;
      this->m_nCount=other.m_nCount;
      this->pLength=other.pLength;
      //set the other object pointer to null
      //so that they do not point to the same address
      other.m_nCount=0;
      other.pLength=nullptr;
   }
   //Move assignment operator
   Test& operator=(Test&& other) noexcept{
      cout<<"Test assignment operator"<<endl;
      if(this!=&other){
         this->m_nCount=other.m_nCount;
         this->pLength=other.pLength;
         //set the other object pointer to null
         //so that they do not point to the same address
         other.m_nCount=0;
         other.pLength=nullptr;
      }
      return *this;
   }
   virtual ~Test()
   {
		//cout<<"Test destructor"<< m_nCount << "\n";
   }
};
Test createTest()
{
	Test t;
	return t;
}
int main()
{
	cout<<"Creating a Test object"<<"\n";
	Test t;
	cout<<"Creating a Test object from an existing object"<<"\n";
	Test t1=t;
	cout<<"Assiging a Test object to other object"<<"\n";
	Test t2;
	t2=t1;
	cout<<"Creating a Test object with one arg constructor"<<"\n";
	Test t3=10;
	cout<<"calling a method that returns Test object"<<"\n";
   Test t4=createTest();
   cout<<"Adding Test object into vector"<<endl;
   vector<Test> vecTest;
   cout<<"First vector push"<<endl;
   vecTest.push_back(t);
   cout<<"Second vector push"<<endl;
   vecTest.push_back(t1);
   cout<<"third vector push"<<endl;
   vecTest.push_back(t2);
   cout<<"fourth vector push"<<endl;
   vecTest.push_back(t3);
	return 0;
}
