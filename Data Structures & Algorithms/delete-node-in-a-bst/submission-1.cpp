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
    TreeNode* find_min(TreeNode* node) {
        if (node && node->left) {
            return find_min(node->left);
        } else {
            return node;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root->left == nullptr && root->right == nullptr && root->val != key) {
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                TreeNode* min_node = find_min(root->right);
                root->val = min_node->val; // copy over value
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};