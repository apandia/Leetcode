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
//Constraint: The problem considers sorting based on both rows and column
//TC: O(LOG N * LOG N * LOG N * N) ~ O(N Log ^3 N)
//Log N operation for each map(2 numbers), multiset and in total N elements
class Solution {
public:
    void traverseTree(TreeNode* root, int column, int row, map<int, map<int, multiset<int>>>& m)
    {
        if(root == nullptr)
            return;
        
        m[column][row].insert(root->val);
        
        traverseTree(root->left, column-1, row+1, m);
        traverseTree(root->right, column+1, row+1, m);        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        
        map<int, map<int, multiset<int>>> m;
        
        traverseTree(root, 0, 0, m);
        
        for(auto it1 : m)
        {
            vector<int> tmp;
            for(auto it2 : it1.second)
            {
                for(auto it3 : it2.second)
                {
                    tmp.push_back(it3);                    
                }                
            }
            result.push_back(tmp);
        }
        
        return result;        
    }
};
