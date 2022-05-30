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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root == nullptr)
            return result;
        
        TreeNode* current = root;
        
        while(current != nullptr)
        {
            if(current->left == nullptr)
            {
                result.push_back(current->val);
                current = current->right;
                
            }
            else
            {
                TreeNode* rightmostNodeInLeftTree = current->left;
                while(rightmostNodeInLeftTree->right && rightmostNodeInLeftTree->right != current)
                {
                    rightmostNodeInLeftTree = rightmostNodeInLeftTree->right;
                }
                
                if(rightmostNodeInLeftTree->right == nullptr)
                {
                    rightmostNodeInLeftTree->right = current;
                    result.push_back(current->val);
                    current = current->left;
                }
                else
                {
                    rightmostNodeInLeftTree->right = nullptr;
                    current = current->right;                    
                }
            }
        }
        return result;
    }
};
