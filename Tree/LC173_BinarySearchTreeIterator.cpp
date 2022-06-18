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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);        //Left
    }
    
    int next() {
        TreeNode* node = bst.top(); //Node
        bst.pop();
        
        pushLeftNodes(node->right); //Right
        return node->val;
    }
    
    bool hasNext() {
        return !bst.empty();        
    }

private:
    void pushLeftNodes(TreeNode* root)
    {
        while(root)
        {
            bst.push(root);
            root = root->left;
        }
    }
private:
    stack<TreeNode*> bst;
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
