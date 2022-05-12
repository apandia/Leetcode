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
    int getPathSum(TreeNode* root, int& maxPathSum)
    {
        if(root == nullptr)
            return 0;
        
        int leftSum = max(0, getPathSum(root->left, maxPathSum));
        int rightSum = max(0, getPathSum(root->right, maxPathSum));
        
        maxPathSum = max(maxPathSum, leftSum+rightSum+root->val);
        
        return max(leftSum, rightSum)+root->val;        
    }
    
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        
        int sum = getPathSum(root, maxPathSum);
        
        return maxPathSum;
        
    }
};
