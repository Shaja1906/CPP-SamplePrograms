#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

bool IsPalindrome(string str) {
	int nStrLen = str.length();
	if (nStrLen == 0) {
		cout << "The string is empty." << endl;
		return 0;
	}
	// abba aba
	for (int nCount = 0; nCount < nStrLen/2; nCount++) {
		if (str[nCount] != str[nStrLen-1-nCount]) {
			return 0;
		}
	}
	return 1;
}

int main(){
	string str = "";
	cout << "Enter the Straing to check if it is a palindrome" << endl;
	/*use getline to get the input string from user*/
	getline(cin, str);
	if (IsPalindrome(str)) {
		cout << "The given string is a palindrome" << endl;
	}
	else {
		cout << "The given string is not a plaindrome" << endl;
	}
	return 0;	
}
