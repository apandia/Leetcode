/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Note: Head pointer is not given.
//So actually we are not deleting the node, rather we are setting the value of node with value of next node and setting the next pointer to next node of next node
class Solution {
public:
    void deleteNode(ListNode* node) {        
        node->val = node->next->val;
        node->next = node->next->next;        
    }
};
