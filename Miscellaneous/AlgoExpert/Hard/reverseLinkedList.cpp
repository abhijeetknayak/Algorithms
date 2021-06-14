using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
	LinkedList * last = head;
	LinkedList * first = head;
	
	while(last->next != NULL) {
		last = last->next;
	}	
	
	while(first != last) {
		LinkedList * temp = first->next;
		first->next = last->next;
		last->next = first;
		first = temp;
	}
	
  return last;
}
