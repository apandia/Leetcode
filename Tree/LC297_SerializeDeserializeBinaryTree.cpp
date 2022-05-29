/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // AP - Level order traversal is used
    string serialize(TreeNode* root) {
        string str = "";
        
        if(root == nullptr)
            return str;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr == nullptr)
                {
                    str.append("*,");
                }
                else
                {
                    str.append(to_string(curr->val)+',');
                }
                
                if(curr != nullptr)
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        
        return str;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        
        stringstream ss(data);
        string token;
        
        getline(ss, token, ',');
        
        TreeNode* root = new TreeNode(stoi(token));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr != nullptr)
            {            
                getline(ss, token, ',');
                if(token == "*")
                {
                    curr->left = nullptr;
                }
                else
                {
                    curr->left = new TreeNode(stoi(token));
                    q.push(curr->left);
                }
                
                getline(ss, token, ',');
                if(token == "*")
                {
                    curr->right = nullptr;
                }
                else
                {
                    curr->right = new TreeNode(stoi(token));
                    q.push(curr->right);
                }
            }            
        }   
        
        return root;        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
