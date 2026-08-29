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
    stack<TreeNode*> nodes;
    vector<int> arr;
    int iter = -1;
    BSTIterator(TreeNode* r) {
        TreeNode* curr = r;
        while (!nodes.empty() || curr) {
            if (curr) {
                nodes.push(curr);
                curr=curr->left;
            } else {
                curr = nodes.top();
                nodes.pop();
                arr.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    
    int next() {
        iter++;
        return arr[iter];
    }
    
    bool hasNext() {
        return iter != arr.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */