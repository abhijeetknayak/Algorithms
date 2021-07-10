#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
	LinkedList * first = head;
	LinkedList * second = head;
	while(true) {
		first = first->next;
		second = second->next->next;
		
		if (first == second) break;
	}
	
	first = head;
	while(first != second) {
		first = first->next;
		second = second->next;
	}
  return first;
}
