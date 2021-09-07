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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = new ListNode(-1);
        temp->next = head;
        ListNode * left = temp, * right = temp;
        while(right != NULL) {
            int count = k - 1;
            
            for (int i = 0; i < k && right != NULL; i++) {
                right = right->next;                
            }
            if (right == NULL || left == right) break;
            cout << left->val << " " << right->val << endl;
            
            /* Now Reverse the nodes */
            while(count > 0) {
                ListNode * t = left->next->next;
                left->next->next = right->next;
                right->next = left->next;
                left->next = t;
                count--;
            }
            
            for (int i = 0; i < k - 1; i++) {
                right = right->next;
            }
            
            left = right;
                        
        }
        
        return temp->next;        
    }
};
