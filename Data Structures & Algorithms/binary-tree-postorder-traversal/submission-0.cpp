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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> nodes;
        stack<bool> visited;
        TreeNode* curr = root;
        vector<int> ans;
        nodes.push(curr);
        visited.push(false);
        while (!nodes.empty()) {
            curr = nodes.top(); nodes.pop();
            bool v = visited.top(); visited.pop();
            if (v) {
                ans.push_back(curr->val);
            } else {
                nodes.push(curr);
                visited.push(true);
                if (curr->right) {
                    nodes.push(curr->right);
                    visited.push(false);
                }
                if (curr->left) {
                    nodes.push(curr->left);
                    visited.push(false);
                }
            }
        }
        return ans;
    }
};