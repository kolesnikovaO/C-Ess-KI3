#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int val);
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
}
class List
{
public:
	List();
	void push_front(int value);
	bool pop_front(int value);
private:
	Node* head;
};
List::List() : head(nullptr)
{
}
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
	//
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	int value = 0;
	while (list.pop_front(3))
	{
		cout << value << endl;
	}
	return 0;
}
