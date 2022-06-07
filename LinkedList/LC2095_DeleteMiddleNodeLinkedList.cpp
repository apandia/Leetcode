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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode tmp(0, head);
        
        ListNode* slow = &tmp;
        ListNode* fast = &tmp;

        while (fast->next && fast->next->next) {
          slow = slow->next;
          fast = fast->next->next;
        }

        // delete the middle node
        slow->next = slow->next->next;
        return tmp.next;    
    }
};
