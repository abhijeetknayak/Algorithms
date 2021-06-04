using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
	LinkedList * head = new LinkedList(-1), * temp = head;
	int carry = 0;
	int num_sum = 0;
	while(linkedListOne != NULL || linkedListTwo != NULL) {
		if (linkedListOne != NULL && linkedListTwo != NULL) {
			num_sum = linkedListOne->value + linkedListTwo->value + carry;
			head->next = new LinkedList(num_sum % 10);
			carry = num_sum / 10;
			linkedListOne = linkedListOne->next;
			linkedListTwo = linkedListTwo->next;
			head = head->next;
		}
		else if (linkedListOne != NULL) {
			num_sum = linkedListOne->value + carry;
			head->next = new LinkedList(num_sum % 10);
			carry = num_sum / 10;
			linkedListOne = linkedListOne->next;
			head = head->next;
		}
		else {
			num_sum = linkedListTwo->value + carry;
			head->next = new LinkedList(num_sum % 10);
			carry = num_sum / 10;
			linkedListTwo = linkedListTwo->next;
			head = head->next;
		}
	}
	if (carry != 0) head->next = new LinkedList(carry);
  return temp->next;
}
