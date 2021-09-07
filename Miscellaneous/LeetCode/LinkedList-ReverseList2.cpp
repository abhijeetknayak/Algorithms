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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode * temp = new ListNode (-1);
        temp->next = head;
        ListNode * leftNode = temp, * rightNode = temp;
        for (int i = 0; i < left - 1; i++) {
            leftNode = leftNode->next;
        }
        for (int i = 0; i < right; i++) {
            rightNode = rightNode->next;
        }
        int count = (right - left);
        while(count > 0) {
            ListNode * t = leftNode->next->next;
            leftNode->next->next = rightNode->next;
            rightNode->next = leftNode->next;
            leftNode->next = t;
            
            count--;
        }
        
        return temp->next;
    }
};
