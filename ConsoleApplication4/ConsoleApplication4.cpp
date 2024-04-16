//ahmad hosseini - 4001406901

#include <iostream>
using namespace std;
class node {
public:
	int value;
	node* next;
	node(int val) {
		value = val;
		next = nullptr;
	}
};
class list {
private:
	node* list_end=nullptr, *list_head = nullptr;
	int list_size=0;
	
public:
	node* begin();
	node* end();
	bool isempty();
	int count(int);
	int size();
	void insert(int pos, int val);
	int del(int pos);
	void erase(int val);


};

node* list::begin()
{
	return list_head;
}
node* list::end()
{
	return list_end;
}
bool list::isempty() {
	if (list_head == nullptr) {
		return 1;
	}
	else {
		return 0;
	}
}

int list::count(int val)
{
	int counter=0;
	node* ptr=begin();
	if (!isempty()) {
		for (int i = 0; i < size(); i++) {
			if (ptr->value == val) {
				counter++;
			}
			ptr = ptr->next;
		}
	}
	return counter;
}

int list::size()
{	
	return list_size;
}

void list::insert(int pos, int val)
{	
	node* newnode = new node(val);
	if (pos == 0) {
		newnode->next = begin();
		list_head = newnode;
		if (list_size == 0) {
			list_end = list_head;
		}
		list_size++;
	}
	else if (pos == size()) {
		list_end ->next = newnode;
		list_end = list_end->next;
		list_size++;
	}
	else if (pos > 0 && pos < size()) {
		node* ptr = begin();
		for (int i = 1; i < pos; i++) {
			ptr = ptr->next;
		}
		newnode->next = ptr->next;
		ptr->next = newnode;
		list_size++;
	}
	else {
		return;
	}
}

int list::del(int pos) {
	node* current = begin(), * pre = nullptr;
	if (pos > 0 && pos < list_size) {
		for (int i = 0; i < pos; i++) {
			pre = current;
			current = current->next;
		}
		pre->next = current->next;
		int val = current->value;
		list_size--;
		delete current;
		return val;
	}
	else if (pos == 0) {
		int val = current->value;
		list_head = current->next;
		delete current;
		list_size--;
		return val;
	}
	else {
		return NULL;
	}
}

void list::erase(int val)
{
	node* ptr = begin();
	int pos = 0;
	while (ptr!=nullptr)
	{
		if (ptr->value == val) {
			ptr = ptr->next;
			del(pos);
			pos++;
		}
		else {
			ptr = ptr->next;
			pos++;
		}
	}
}

void main() {
	list list;
	list.insert(0, 10);
	list.insert(1, 8);
	list.insert(2, 9);
	cout << list.del(2) << endl;
	cout << list.del(0) << endl;
	cout << list.del(0) << endl;
	cout << "it seems working fine xD" << endl;
}