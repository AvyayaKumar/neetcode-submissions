class Node {
public:
    int val;
    Node *left = nullptr, *right = nullptr;
    Node(int v) {
        val = v;
    }

    Node* insert(Node* node, int n) {
        if (!node) return new Node(n);
        if (n < node->val) {
            node->left = insert(node->left, n);
        } else if (n > node->val) {
            node->right = insert(node->right, n);
        }
        return node;
    }

    vector<int> preorder(Node* root, vector<int>& ans) {
        if (root) {
            ans.push_back(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }
        return ans;
    }
};

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        Node* root = new Node(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            root->insert(root, preorder[i]);
        }
        vector<int> v;
        root->preorder(root, v);
        return (v == preorder);
    }
};
