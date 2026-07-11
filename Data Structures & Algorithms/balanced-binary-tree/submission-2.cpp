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
    int find_depth(TreeNode* node, int curr_depth) {
        if (!node) return curr_depth-1;
        int x = -1; int y = -1;
        if (node->left || node->right) {
            if (node->left) x = find_depth(node->left, curr_depth + 1);
            if (node->right) y = find_depth(node->right, curr_depth + 1); 
        } else return curr_depth;
        return max(x, y);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(find_depth(root->right, 1) - find_depth(root->left, 1)) > 1) return false;
        return (isBalanced(root->right) && isBalanced(root->left));
    } 
};
