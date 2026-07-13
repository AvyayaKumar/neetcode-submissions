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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r_view;
        if (!root) return r_view;
        queue<TreeNode*> bfs; bfs.push(root);
        while (bfs.size() > 0) {
            //level
            int s = bfs.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = bfs.front(); bfs.pop();
                if (node->left) bfs.push(node->left);
                if (node->right) bfs.push(node->right);
                if (i == s-1) r_view.push_back(node->val); 
                
            }
        }
        return r_view;
    }
};
