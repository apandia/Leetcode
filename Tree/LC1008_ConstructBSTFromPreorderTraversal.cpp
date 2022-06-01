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
    TreeNode* buildBST(vector<int>& preorder, int& index, int maxBound)
    {
        if(index == preorder.size() || preorder[index] > maxBound)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[index++]);
        node->left = buildBST(preorder, index, node->val);
        node->right = buildBST(preorder, index, maxBound);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);        
    }
};
