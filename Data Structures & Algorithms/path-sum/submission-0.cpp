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
    bool recurPath(TreeNode* root, int targetSum, int currSum) {
        if(!root) return false;
        if (!root->left && !root->right) {
            return (currSum+root->val == targetSum);
        }
        if (recurPath(root->left, targetSum, currSum+root->val) || recurPath(root->right, targetSum, currSum+root->val)) {
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return recurPath(root, targetSum, 0);    
    }

};