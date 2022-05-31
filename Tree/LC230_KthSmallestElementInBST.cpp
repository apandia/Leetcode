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
    TreeNode* kthSmallestHelper(TreeNode* root, int& k) 
    {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* left = kthSmallestHelper(root->left, k);
        if(left != nullptr)
            return left;
        k--;
        if(k == 0)
            return root;
        
        return kthSmallestHelper(root->right, k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = kthSmallestHelper(root, k);
        
        if(ans != nullptr)
            return ans->val;
        else
            return -1;        
    }
};
