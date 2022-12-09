/* Program to print duplicate characters in a string */
#include <stdio.h>
#include <iostream>
#define MAX_ASCII 256
using namespace std;

void PrintDuplicate(string str) {
	int nStrLen = str.length();
	int aHash[MAX_ASCII] = {0};

	if (0 == nStrLen) {
		cout<<"The String is empty"<<endl;
	}
	
	for(int nCount = 0; nCount<nStrLen; ++nCount) {
		aHash[str[nCount]]++;
		if (aHash[str[nCount]] == 2) {
			cout<<str[nCount];
		}	
	}
	cout << endl;
}

int main() {
	string str;
	cout << "Enter the string to print duplicates" << endl;
	getline(cin, str);
	PrintDuplicate(str);
	return 0;
}
