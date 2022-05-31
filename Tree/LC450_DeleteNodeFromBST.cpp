/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findLastRightNode(TreeNode* node)
    {
        if(node->right == nullptr)
            return node;
        
        return findLastRightNode(node->right);        
    }
    
    TreeNode* deleteNodeHelper(TreeNode* node)
    {
        if(node->left == nullptr)
            return node->right;
        
        if(node->right == nullptr)
            return node->left;
        
        TreeNode* rightChildNode = node->right;
        TreeNode* lastRightNodeInLeftSubtree = findLastRightNode(node->left);
        
        lastRightNodeInLeftSubtree->right = rightChildNode;
        
        return node->left;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        
        if(root->val == key)
            return deleteNodeHelper(root);
        
        TreeNode* curr = root;
        
        while(curr)
        {
            if(key < curr->val)
            {
                if(curr->left && curr->left->val == key)
                {
                    curr->left = deleteNodeHelper(curr->left);
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {                
                if(curr->right && curr->right->val == key)
                {
                    curr->right = deleteNodeHelper(curr->right);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};
