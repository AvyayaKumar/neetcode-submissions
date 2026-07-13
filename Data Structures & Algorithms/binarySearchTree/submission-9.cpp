class TreeMap {
public:
    int key, value;
    TreeMap *left, *right, *root;

    TreeMap() {
        left = nullptr; right = nullptr; root = nullptr;
        key = -1; value = -1;
    }

    void insert(int key, int val) {
        if (!root) {
            root = new TreeMap; root->key = key; root->value = val;
        } else {
            // iterate through to find the spot for key
            TreeMap* curr = root;
            while (true) {
                if (curr->key < key) {
                    if (curr->right) curr=curr->right;
                    else {
                        TreeMap* newNode = new TreeMap; newNode->key = key; newNode->value = val; curr->right = newNode;
                        break;
                    }
                } else if (curr->key > key) {
                    if (curr->left) curr=curr->left;
                    else {
                        TreeMap* newNode = new TreeMap; newNode->key = key; newNode->value = val; curr->left = newNode;
                        break;
                    }
                } else {
                    curr->value = val;
                    break;
                }
            }
        }
    }


    int get(int key) {
        if (!root) return -1;
        TreeMap* curr = root;
        while (true) {
            if (curr->key < key) {
                if (curr->right) curr=curr->right;
                else {
                    return -1;
                }
            } else if (curr->key > key) {
                if (curr->left) curr=curr->left;
                else {
                    return -1;
                }
            } else {
                return curr->value;
            }
        }
    }

    int getMin() {
        if (!root) return -1;
        TreeMap* curr = root;
        while (curr->left) {
            curr=curr->left;
        }
        return curr->value;
    }

    int getMax() {
        if (!root) return -1;
        TreeMap* curr = root;
        while (curr->right) {
            curr=curr->right;
        }
        return curr->value;
    }

    TreeMap* find_min(TreeMap* node) {
        while (node->left && node) {
            node=node->left;
        }
        return node;
    }

    TreeMap* del(TreeMap* node, int key) {
        if (!node) return node;
        if (node->key < key) {
            node->right = del(node->right, key);
        } else if (node->key > key) {
            node->left = del(node->left, key);
        } else {
            if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            } else {
                TreeMap* min_node = find_min(node->right);
                node->value = min_node->value; node->key = min_node->key; // copy over value
                node->right = del(node->right, node->key);
            }
        }
        return node;
    }

    void remove(int key) {
        if (root) root = del(root, key);
    }

    vector<int> getKeys(TreeMap* node, vector<int>& arr) {
        if (!node) return {};
        getKeys(node->left, arr);
        arr.push_back(node->key);
        getKeys(node->right, arr);
        return arr;
    }

    std::vector<int> getInorderKeys() {
        vector<int> ans;
        return getKeys(root, ans);

    }
};
