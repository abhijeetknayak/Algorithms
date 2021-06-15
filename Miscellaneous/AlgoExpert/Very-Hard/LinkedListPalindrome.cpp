using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

bool linkedListPalindrome(LinkedList *head) {
    LinkedList * temp = head, * last, * first = head;
    int count = 0, i = 0;
    
    /* Find length of Linked List, last node */
    while(temp != NULL) {
        count++;
        if (temp->next == NULL) last = temp;
        temp = temp->next;
    }
    
    /* Invert half of the list. If the list has odd number of nodes,
    the first one will be the node that was at the center of the original list */
    while(i < count / 2) {
        temp = first->next;
        first->next = last->next;
        last->next = first;     
        first = temp;
        i++;
    }
    
    /* Ignore first node for new list */
    if (count % 2 != 0) first = first->next;
    
    i = 0;
    last = first;
    
    /* Traverse from the first node to the node in the middle */
    while(i < count / 2) {
        last = last->next;
        i++;
    }
    
    while(last != NULL) {
        if (first->value != last->value) return false;
        first = first->next;
        last = last->next;
    }
    
  return true;
}
