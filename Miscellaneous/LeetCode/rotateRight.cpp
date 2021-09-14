/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode * temp = head, * left = head, * tail = head;
        while(temp != NULL) {
            len++;
            if (temp->next == NULL) {
                tail = temp; break;
            }            
            temp = temp->next;            
        }
        if (len == 0) return NULL;
        
        k = k % len;
        if (k == 0) return head;
        
        for (int i = 0; i < len - k - 1; i++) {
            left = left->next;
        }
        
        tail->next = head;
        head = left->next;
        left->next = NULL;
        
        return head;        
    }
};
