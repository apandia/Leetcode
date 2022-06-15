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
    int getLinkedListLength(ListNode* head)
    {
        ListNode* tmp = head;
        int length = 0;

        while(tmp)
        {
            tmp = tmp->next;
            length++;
        }
        return length;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1)
            return head;
        
        int linkedListLength = getLinkedListLength(head);
        
        ListNode* dummy = new ListNode;
        dummy->next = head;
        
        ListNode *curr, *next;
        ListNode* prev = dummy;
        
        while(linkedListLength >= k)
        {
            curr = prev->next;
            next = curr->next;
            
            for(int i = 0; i < k-1; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;                
            }
            prev = curr;
            linkedListLength -= k;
        }
        return dummy->next;        
    }
};
