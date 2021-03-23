class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *shiftLinkedList(LinkedList *head, int k) {
	int len = 0, temp = 0;
	LinkedList * current = head;

	/* Get Linked list length */
	while(current != NULL) {
		len += 1;
		current = current->next;
	}

	temp = k % len;

	/* Return head if k is a multiple of the linked list length */
	if (temp == 0) return head;

	/* Find node before new head of the linked list */
	int index = ((len - temp) % len) - 1;
	current = head;

	/* Traverse to that node */
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	/* New head node after rotation, set the previous node's next value to NULL */
	LinkedList * newHead = current->next;
	current->next = NULL;

	/* Traverse to the last node and set its next pointer to the actual head */
	if (k > 0) index = temp;
	else index = temp + len;

	current = newHead;
	for (int i = 1; i < index; i++) {
		current = current->next;
	}
	current->next = head;

	return newHead;
}

int main() {
	LinkedList a(0);
	a.next = new LinkedList(1);
	a.next->next = new LinkedList(2);
	a.next->next->next = new LinkedList(3);
	a.next->next->next->next = new LinkedList(4);
	a.next->next->next->next->next = new LinkedList(5);

	LinkedList * p = shiftLinkedList(&a, 14);
	while(p != NULL) {
		cout << p->value << " ";
		p = p->next;
	}
}
