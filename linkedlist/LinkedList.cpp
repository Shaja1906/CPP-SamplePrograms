#include <stdio.h>
#include <iostream>
using namespace std;

class LinkedList {
private:
	int value;
	LinkedList* next;
	LinkedList* head;
public:
	LinkedList(int nVal) {
		this->value = nVal;
		this->next = NULL;
		head = this;
	};
	~LinkedList(){};
	/* Linked List Operations */
	void push_back(int nVal);
	void pop_front();
	void Print();
};

void LinkedList::push_back(int nVal) {
	LinkedList* temp = head;	
	LinkedList* newNode = new LinkedList(nVal);
	cout<<"temp obj created"<< endl;
	while (NULL != temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;	
}

void LinkedList::pop_front() {
	if (NULL == head) {
		cout<< "The list is empty"<<endl;
		return;
	}
	LinkedList* temp = head;
	if (NULL != temp) {
		cout<<"The Popped value is : "<< temp->value<<endl;
		head = temp->next;
		delete temp;
	}
}

void LinkedList::Print() {
	LinkedList* temp = head;
	if (NULL == temp) {
		cout<< " The Linked List is empty" << endl;
		return;
	}
	/* Linked List is not empty. Print it */
	while (NULL != temp) {
		cout << temp->value << endl;
		temp = temp->next;
	}
	
}

int main() {
	LinkedList* list = new LinkedList(10);
	list->Print();	
	list->push_back(11);
	list->push_back(12);
	list->Print();
	list->pop_front();
	list->pop_front();
	list->pop_front();
	list->pop_front();
	return 0;
}
