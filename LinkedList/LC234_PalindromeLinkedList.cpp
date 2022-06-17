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
    ListNode* reverseLinkList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while(head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != nullptr)
            slow = slow->next;
        
        slow = reverseLinkList(slow);
        
        while(slow)
        {
            if(head->val != slow->val)
                return false;
            
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
