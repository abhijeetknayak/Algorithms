#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
	LinkedList * temp = new LinkedList(-1);
	temp->next = head;
	LinkedList * first = temp, * second = temp;
	
	for (int i = 0; i < k; i++) {
		/* Move second to kth element from start node */
		if (second->next != NULL) {
			second = second->next;
		}
	}
	
	while(second->next != NULL) {
		first = first->next;
		second = second->next;
	}
	if (first == temp) {
		head->value = head->next->value;
		head->next = head->next->next;
	}
	else {
		first->next = first->next->next;
	}
}
