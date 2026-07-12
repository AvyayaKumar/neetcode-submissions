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
    vector<int> mergeSort(vector<int> arr) {
        vector<int> ans;
        if (arr.size() <= 1) {
            return arr;
        }
        vector<int> newarr1; vector<int> newarr2;
        for (int i = 0; i < (arr.size()/2); i++) {
            newarr1.push_back(arr[i]);
        }
        for (int i = arr.size()/2; i < arr.size(); i++) {
            newarr2.push_back(arr[i]);
        }
        newarr1 = mergeSort(newarr1); newarr2 = mergeSort(newarr2);
        int p1 = 0; int p2 = 0;
        while (p1 < newarr1.size() || p2 < newarr2.size()) {
            if (p1 >= newarr1.size() && p2 < newarr2.size()) {
                ans.push_back(newarr2[p2]); p2++;
            } else if (p1 < newarr1.size() && p2 >= newarr2.size()) {
                ans.push_back(newarr1[p1]); p1++;
            } else {
                if (newarr1[p1] <= newarr2[p2]) {
                    ans.push_back(newarr1[p1]); p1++;
                } else {
                    ans.push_back(newarr2[p2]); p2++;
                }
            }
        }
        return ans;
    }

    int binary_search(vector<int> sorted_arr, int target) {
        int left = 0; int right = sorted_arr.size()-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (sorted_arr[mid] < target) {
                left = mid+1;
            } else if (sorted_arr[mid] > target) {
                right = mid-1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> sorted_arr = mergeSort(inorder);
        if (inorder.size() == 0) {
            return nullptr;
        } else if (inorder.size() == 1) {
            return new TreeNode(inorder[0]);
        } else {
            TreeNode* root = new TreeNode();
            for (int i = 0; i < preorder.size(); i++) {
                // if preorder[i] is in inorder
                if (binary_search(sorted_arr, preorder[i]) != -1) {
                    root->val = preorder[i];
                    break;
                }
            }

            vector<int> left_subtree_inorder;
            int i = 0;
            while (i < inorder.size()) {
                if (inorder[i] == root->val) {
                    break;
                } else {
                    left_subtree_inorder.push_back(inorder[i]);
                }
                i++;
            }
            vector<int> right_subtree_inorder;
            while (i < inorder.size()) {
                if (inorder[i] != root->val) {
                    right_subtree_inorder.push_back(inorder[i]);
                }
                i++;
            }
            // for (int i : left_subtree_inorder) {
            //     cout << i << " ";
            // }
            // cout << " left" << endl;
            // for (int i : right_subtree_inorder) cout << i << " ";
            // cout << endl;
            root->left = buildTree(preorder, left_subtree_inorder);
            root->right = buildTree(preorder, right_subtree_inorder);

            return root;
            
        }
        
    }
};
