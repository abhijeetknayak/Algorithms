#include <iostream>

using namespace std;

#define MAX_SPACE 6
class Queue
{
private:
	int start;
	int end;
	int array[MAX_SPACE];

public:
	Queue();
	void push(int value);
	int pop(void);
};

Queue::Queue() {
	/* Constructor Definition */
	start = -1;
	end = -1;
}

void Queue::push(int value) {
	if (end == -1 && start == -1) {
		start = 0; end = 0;
		array[start] = value;
	}
	else if (end < MAX_SPACE - 1) {
		array[++end] = value;
	}
	else if (start != 0) {
		/* Circular Buffer */
		end = 0;
		array[end] = value;
	}
	else {
		cout << "Queue is full!" << endl;
		return;
	}
}

int Queue::pop(void) {
	if (start == -1) {
		cout << "Queue is empty" << endl;
		return NULL;
	}

	if (end < start && start == MAX_SPACE - 1) {
		int data = array[start];
		start = 0;

		return data;
	}

	return array[start++];
}

void main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(2);
	q.push(2);
	q.push(2);
	q.push(2);

	q.push(7);

	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	q.push(3);
	q.push(3);
	q.push(3);


}