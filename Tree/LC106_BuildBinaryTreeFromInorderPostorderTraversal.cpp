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
    TreeNode* buildTreeRecursive(vector<int>& inorder, int inorderStart, int inorderEnd, vector<int>& postorder, int postorderStart, int postorderEnd, unordered_map<int, int>& inoderNodeMap)
    {
        if(inorderStart > inorderEnd || postorderStart > postorderEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postorderEnd]);
        
        int rootNodeIndexInorderMap = inoderNodeMap[root->val];
        int numNodesAtLeft = rootNodeIndexInorderMap - inorderStart;        
        
        root->left =  buildTreeRecursive(inorder, inorderStart, rootNodeIndexInorderMap-1, postorder, postorderStart, postorderStart+numNodesAtLeft-1, inoderNodeMap);
        
        root->right = buildTreeRecursive(inorder, rootNodeIndexInorderMap+1, inorderEnd, postorder, postorderStart+numNodesAtLeft, postorderEnd-1, inoderNodeMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return nullptr;
        
        unordered_map<int, int> inorderNodeMap;
        
        unordered_map<int, int> inoderNodeMap;
        for(int i = 0; i< inorder.size(); i++)
        {
            inoderNodeMap[inorder[i]] = i;
        }
        
        return buildTreeRecursive(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inoderNodeMap);        
    }
};
