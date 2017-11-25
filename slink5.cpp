#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int val);
	int value;
	//~Node();
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
	//	cout << "+Node" << endl;
}
//Node::~Node()
//{
//	cout << "-Node" << endl;
//}

class List
{
public:
	List();
	void push_back(int value);
	//~List();
	void push_front(int value);
	bool pop_front(int value);
	bool pop_back(int value);
	int size();
private:
	Node* head;
	Node* tail;
};
int List::size() {
	Node *t = head;
	int i = 0;
	while (t != nullptr) {
		t = t->next;
		++i;
	}
	return i;
}
List::List() : head(nullptr)
{

}
//List::~List() {
//	Node *t = head, *next;
//	while (t != nullptr)
//	{
//		next = t->next;
//		delete t;
//		t = next;
//	}
//}
void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head = new_head;
	if (tail == nullptr)
		tail = new_head;
}
void List::push_back(int value)
{
	// implement me!
	Node *new_tail = new Node(value);
	new_tail->next = nullptr;
	if (tail != nullptr)
		tail->next = new_tail;
	tail = new_tail;
	if (head == nullptr)
		head = new_tail;
}

bool List::pop_front(int value)
{
	Node *t = head, *prev = nullptr;

	while (t != nullptr) {
		if (t->value == value) {

			if (prev == nullptr) {
				prev = head;
				head = head->next;
				if (head->next == nullptr)
					tail = head;
				delete prev;
			}
			else
			{
				if (t->next == nullptr)
					tail = prev;
				prev->next = t->next;
				delete t;
			}

			return true;
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
	return false;
}
bool List::pop_back(int value) {
	Node *t = head,*pre=nullptr, *temp=nullptr;
	while (t->next!=nullptr)
	{
		if (t->value == value)
		{
			temp = pre;
		}
		pre = t;
		t = t->next;
	}
	if (tail->value == value) {
		temp = pre;
		tail = pre;
	}
		
	if (temp != nullptr) {
		t = temp->next;
		temp->next = t->next;

		delete t;
		return true;
	}
	return false;
	
}
int main()
{
	List list;
	//
	list.push_front(2);
	list.push_front(2);
	list.push_front(3);
	list.push_front(2);
	list.push_front(4);
	int value = 0;
	while (list.pop_back(value))
	{
		cout << value << endl;
	}
	return 0;

}

