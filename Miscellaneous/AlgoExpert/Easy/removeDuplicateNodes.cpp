using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
	if (linkedList == NULL) return NULL;
	LinkedList * head = new LinkedList(-1);
	head->next = linkedList;
	
	int cur_val = linkedList->value;
	
	while(linkedList->next != NULL) {
		if (linkedList->next->value != cur_val) {
			cur_val = linkedList->next->value;
			linkedList = linkedList->next;
		}
		else {
			linkedList->next = linkedList->next->next;
		}
	}
  return head->next;
}
