#include <iostream>

using namespace std;

struct Node {
	int data;
	Node * next;
	Node* prev;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList();
	void add(int value);
	void addAtBeg(int value);
	void addAfter(int index, int value);
	void del(int value);
	void display();
	int count();
	~LinkedList();
};

/* Function Definitions */
LinkedList::LinkedList() {
	head = NULL;
}

void LinkedList::add(int value) {
	if (head == NULL) return;

	/* Delete all nodes in the linked list */
	Node * q;
	while (head != NULL) {
		q = head->next;
		delete head;
		head = q;
	}
	delete head;
}

void LinkedList::add(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL) {
		/* First node in the list */
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

void LinkedList::addAfter(int index, int value) {

}

void LinkedList::addAtBeg(int value) {
	/* Create New Node */
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL) head = newNode;
	else {
		/* Add new node at the beginning */
		newNode->next = head;
		head = newNode;
	}
}

void LinkedList::del(int value) {
	/* Delete all nodes with that value */
	Node * temp = head;
	if (head->data == value) {
		head = temp->next;
		delete temp;
		return;
	}

	while (temp != NULL) {
		if (temp->data == value) {

		}
	}
}

void LinkedList::display() {

}

int LinkedList::count() {

}

LinkedList::~LinkedList() {

}