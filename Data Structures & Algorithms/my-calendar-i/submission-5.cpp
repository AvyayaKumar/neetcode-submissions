class TreeNode {
public:
    int l, r;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(int startTime, int endTime) {
        l = startTime;
        r = endTime;
    }

    bool insert(int startTime, int endTime) {
        // overlap
        if (!(endTime <= l || startTime >= r)) {
            return false;
        }

        // goes left
        if (endTime <= l) {
            if (!left) {
                left = new TreeNode(startTime, endTime);
                return true;
            }

            return left->insert(startTime, endTime);
        }

        // goes right
        else {
            if (!right) {
                right = new TreeNode(startTime, endTime);
                return true;
            }

            return right->insert(startTime, endTime);
        }
    }
};

class MyCalendar {
public:
    TreeNode* root = nullptr;

    MyCalendar() {}

    bool book(int startTime, int endTime) {
        if (!root) {
            root = new TreeNode(startTime, endTime);
            return true;
        }

        return root->insert(startTime, endTime);
    }
};