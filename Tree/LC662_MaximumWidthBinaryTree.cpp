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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;

        if(root == nullptr)
            return maxWidth;

        queue<pair<TreeNode*, int>> q; //pair of node and node index
        q.push({root, 0});

        while(!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int first, last;

            for(int i = 0; i < size; i++)
            {
                long currId = q.front().second - min;
                TreeNode* current = q.front().first;

                q.pop();

                if(i == 0)
                    first = currId;

                if(i == size-1)
                    last = currId;

                if(current->left)
                    q.push({current->left, 2*currId+1});

                if(current->right)
                    q.push({current->right, 2*currId+2});
            }

            maxWidth = max(maxWidth, last-first+1);
        }

        return maxWidth;
    }
};
