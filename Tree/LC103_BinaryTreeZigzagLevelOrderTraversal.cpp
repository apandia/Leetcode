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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == nullptr){
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int currentLevel = 0;
        
        while(!q.empty())
        {
            vector<int> currentLevelNode;
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                
                 if(curr->right != nullptr){
                    q.push(curr->right);
                }
                
                currentLevelNode.push_back(curr->val);
            }
            
            if(currentLevel%2 != 0){
                reverse(currentLevelNode.begin(), currentLevelNode.end());
            }
            currentLevel++;
            
            result.push_back(currentLevelNode);
        }
        
        return result;        
    }
};
