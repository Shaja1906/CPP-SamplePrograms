/* This is a program to get the maximum occuring character in string */
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX_ASCII 256
using namespace std;

char maxOccuringChar(string str) {
	int nStrLen = str.length();
	if ( 0 == nStrLen) {
		cout << "The String is empty" << endl;
		return 0;
	}
	/* Find the max occuring character */
	// Hash array
	int aCount[MAX_ASCII] = {0}; // Initialized to 0
	int max = 0; // To hold the maximum occurance
	char cMax; // To hold the max occuring character
	for (int nCount = 0; nCount<nStrLen; nCount++){
		aCount[str[nCount]]++;
		if (max < aCount[str[nCount]]){
			max = aCount[str[nCount]];
			cMax = str[nCount];
		}
	}
	return cMax;	
}

int main() {
	string str = ""; //Initializing with empty string
	cout << "Enter the input string" << endl;
	getline(cin, str);
	cout << "The maximum ocuuring string is " << maxOccuringChar(str) << endl;
	return 0;
}
