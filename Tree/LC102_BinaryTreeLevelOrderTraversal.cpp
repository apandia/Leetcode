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
 //SC: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == nullptr)
        {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> currLevelNodes;
            int queueSize = q.size();
            
            for(int i = 0; i < queueSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
                
                currLevelNodes.push_back(curr->val);                
            }
            
            result.push_back(currLevelNodes);
        }
        
        return result;        
    }
};
