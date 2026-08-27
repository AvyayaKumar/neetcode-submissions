class Node {
public:
    int sum;
    int L;
    int R;
    Node* left;
    Node* right;

    Node(int total, int L_inp, int R_inp) {
        sum = total;
        L = L_inp;
        R = R_inp;
        left = nullptr;
        right = nullptr;
    }

    static Node* build(vector<int>& nums, int L, int R) {
        if (L == R) {
            return new Node(nums[L], L, R);
        }

        int M = (L+R) / 2;
        Node* root = new Node(-1, L, R);
        root->left = Node::build(nums, L, M);
        root->right = Node::build(nums, M+1, R);
        root->sum = root->right->sum + root->left->sum;
        return root;
    }
    
    void update(int index, int val) {
        if (L == R && L == index) {
            sum = val;
            return;
        }
        int M = (L+R) / 2;
        if (index <= M) {
            left->update(index, val);
        } else {
            right->update(index, val);
        }
        sum = left->sum + right->sum;

    }
    
    int query(int Lq, int Rq) {
        if (L == Lq && R == Rq) return sum;
        int M = (L+R)/2;
        if (Rq <= M) {
            return left->query(Lq, Rq);
        } else if (Lq > M) {
            return right->query(Lq, Rq);
        } else {
            return left->query(Lq, M) + right->query(M+1, Rq);
        }
    }
};

class SegmentTree {
public:
    Node* root;
    SegmentTree(vector<int>& nums) {
        root = Node::build(nums, 0, nums.size()-1);
        // cout << root->left->sum << endl;
    }
    
    void update(int index, int val) {
        root->update(index, val);
    }
    
    int query(int L, int R) {
        return root->query(L, R);
        // return 0;
    }
};
