/* Program to remove duplicated from a string */
#include <stdio.h>
#include <iostream>

using namespace std;
// eg: Shajahan
void RemoveDuplicate(string str) {
	string strRes = "";
	int nIndex = 0;
	int nStrLen = str.length();
	short int nDup = 0;
	if (0 == nStrLen) {
		cout<< "The String is empty" << endl;
		return;
	}
	for (int nCount1 = 0; nCount1<nStrLen; ++nCount1) {
		nDup = 0;
		for(int nCount2 =nCount1+1; nCount2<nStrLen; ++nCount2) {
			if(str[nCount1] == str[nCount2]){
				nDup = 1;
				break;
			}	
		}
		if (1 != nDup) {
			strRes[nIndex++] = str[nCount1];
		}
	}
	cout << "The result string is "<< endl;
	for (int nCount = 0; nCount < nIndex; ++nCount) {
		cout << strRes[nCount];	
	}
	cout<<endl;	
}

int main() {
	string str;
	cout << "Enter the input string " << endl;	
	getline(cin, str);
	RemoveDuplicate(str);	
}
