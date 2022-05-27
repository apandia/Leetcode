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
    int leftHeight(TreeNode* node){
        int leftHeight = 0;
        while(node){
            leftHeight++;
            node = node->left;
        }
        return leftHeight;
    }
    
    int rightHeight(TreeNode* node){
        int rightHeight = 0;
        while(node){
            rightHeight++;
            node = node->right;
        }
        return rightHeight;
    }
    
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh == rh)
            return ((1<<lh)-1);
        
        return 1+countNodes(root->left)+countNodes(root->right);       
    }
};
