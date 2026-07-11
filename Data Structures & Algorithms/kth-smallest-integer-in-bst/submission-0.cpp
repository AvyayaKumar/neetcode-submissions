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
    vector<int>* arr = new vector<int>;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        kthSmallest(root->left, k);
        (*arr).push_back(root->val);
        kthSmallest(root->right, k);

        if ((*arr).size() >= k) {
            return (*arr)[k-1];
        } 
        return -1;
        
    }
};
