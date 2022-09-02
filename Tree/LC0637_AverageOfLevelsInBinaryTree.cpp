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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            double sum = 0;

            for(int counter = 0; counter < size; counter++)
            {
                TreeNode* current = q.front();
                q.pop();

                sum += current->val;

                if(current->left)
                {
                    q.push(current->left);
                }

                if(current->right)
                {
                    q.push(current->right);
                }
            }

            result.push_back(sum/size);
        }

        return result;        
    }
};
