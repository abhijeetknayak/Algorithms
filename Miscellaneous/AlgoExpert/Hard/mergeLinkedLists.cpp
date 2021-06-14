#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
	LinkedList * temp = new LinkedList(-1);
	if (headOne == NULL) return headTwo;
	if (headTwo == NULL) return headOne;
	
	LinkedList * head = temp;
	
	while(headOne != NULL && headTwo != NULL) {
		/* Both Non NULL */
		if (headOne->value <= headTwo->value) {
			temp->next = headOne;
			headOne = headOne->next;
			temp = temp->next;
		}
		else {
			temp->next = headTwo;
			headTwo = headTwo->next;
			temp = temp->next;
		}
	}
	
	if (headOne == NULL) temp->next = headTwo;
	else temp->next = headOne;
	
  return head->next;
}
