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
    void flattenBinaryTreeRecursive(TreeNode* root, TreeNode** prev)
    {
        if(root == nullptr)
            return;
        
        flattenBinaryTreeRecursive(root->right, prev);
        flattenBinaryTreeRecursive(root->left, prev);
        
        root->right = *prev;
        root->left = nullptr;
        *prev = root;        
    }
    
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenBinaryTreeRecursive(root, &prev);
    }
};
