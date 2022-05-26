/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(curr && curr->left){
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr && curr->right){
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        if(root == nullptr)
            return result;

        unordered_map<TreeNode*, TreeNode*> parentMap; //key-> node, value-> parent

        markParents(root, parentMap);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int currDistance = 0;

        while(!q.empty())
        {
            if(currDistance == k)
                break;

            currDistance++;

            int size = q.size();
            for(int i =0; i < size; i++)
            {
                TreeNode* current = q.front();
                q.pop();

                if(current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if(current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if(parentMap[current] && !visited[parentMap[current]])
                {
                    q.push(parentMap[current]);
                    visited[parentMap[current]] = true;
                }
            }
        }

        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();

            result.push_back(currNode->val);
        }

        return result;        
    }
};
