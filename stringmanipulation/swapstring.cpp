#include <stdio.h>
#include <iostream>
using namespace std;

/* use double pointer to refelect the changes done
 * inside the method */
void swap(char** str1, char** str2) {
	char* temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int main() {
	char* str1 =  (char*)("Shaja");
	char* str2 = (char*)("han");
	swap(&str1, &str2);
	cout<< "String str1 is : " << str1 <<endl;
	cout<< "String str2 is : " << str2 <<endl;
	return 0;
}
