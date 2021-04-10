#include <iostream>

using namespace std;

#define MAX_SPACE 6

class Stack
{
private:
	int array[MAX_SPACE];
	int top;

public:
	Stack();
	void push(int value);
	int pop(void);
};

Stack::Stack() {
	/* Constructor Definition */
	top = -1;
}

void Stack::push(int value) {
	/* Push an item into the stack */
	if (top < MAX_SPACE - 1) {
		array[++top] = value;
	}
	else {
		cout << "Stack is full!" << endl;
		return;
	}
}

int Stack::pop() {
	if (top == -1) {
		cout << "Stack is Empty!" << endl;
		return NULL;
	}

	int data = array[top];
	top--;

	return data;
}
