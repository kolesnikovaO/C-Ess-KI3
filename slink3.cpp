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
	//~List();
	void push_front(int value);
	bool pop_front(int value);
	int size();
private:
	Node* head;
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
}
bool List::pop_front(int value)
{
	Node *t = head, *prev = nullptr;

	while (t != nullptr) {
		if (t->value == value) {
			if (prev == nullptr) {
				prev = head;
				head = head->next;
				delete prev;
			}
			else
			{
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
int main()
{
	List list; 
	//cout << list.size() << endl;
	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}
	cout << endl;
	for (int i = 0; i <= 3; i++)
	{
		int value;
		list.pop_front(i);
		cout << "popped " << i << ", size: " << list.size() << endl;
	}
	return 0;

}
