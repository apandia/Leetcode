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
    TreeNode* buildTreeRecursive(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd, unordered_map<int, int>& inoderNodeMap)
    {
        if(preorderStart > preorderEnd || inorderStart > inorderEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        
        int rootNodeIndexInorderMap = inoderNodeMap[root->val];
        int numNodesAtLeft = rootNodeIndexInorderMap - inorderStart;        
        
        root->left =  buildTreeRecursive(preorder, preorderStart+1, preorderStart+numNodesAtLeft, inorder, inorderStart, rootNodeIndexInorderMap-1, inoderNodeMap);
        
        root->right = buildTreeRecursive(preorder, preorderStart+numNodesAtLeft+1, preorderEnd, inorder, rootNodeIndexInorderMap+1, inorderEnd, inoderNodeMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size())
            return nullptr;
        
        unordered_map<int, int> inoderNodeMap;
        for(int i = 0; i< inorder.size(); i++)
        {
            inoderNodeMap[inorder[i]] = i;
        }
        
        TreeNode* root = buildTreeRecursive(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inoderNodeMap);
        
        return root;        
    }
};
