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
//TC: O(N)
//SC: O(N) (for skewed tree)
class Solution {
public:
    bool traverseTree(TreeNode* root1, TreeNode* root2)
    {
        if((root1 == nullptr) || (root2 == nullptr))
            return (root1 == root2);
        
        return ((root1->val == root2->val) &&
               traverseTree(root1->left, root2->right) &&
               traverseTree(root1->right, root2->left));
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return traverseTree(root->left, root->right);    
    }
};
