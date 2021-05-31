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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(true) {
            int min_idx = -1, min_val = INT_MAX;
            for (int i = 0; i < k; i++) {
                if (lists[i] != NULL) {
                    if (lists[i]->val < min_val) {
                        min_idx = i;
                        min_val = lists[i]->val;
                    }
                }
            }
            
            if (min_idx != -1) {
                temp->next = lists[min_idx];
                lists[min_idx] = lists[min_idx]->next;
                temp = temp->next;
            }
            else { break; }
        }
        return head->next;
    }
};
