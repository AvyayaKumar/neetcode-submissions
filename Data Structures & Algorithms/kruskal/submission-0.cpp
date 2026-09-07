class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) {
        for (int i = 0; i <= n-1; i++) {
            par_[i] = i;
            rank_[i] = 0;
        }
    }

    int find(int n) {
        int p = par_[n];
        while (p != par_[p]) {
            par_[p] = par_[par_[p]];
            p = par_[p];
        }
        return p;
    }

    bool _union(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank_[p1] > rank_[p2]) {
            par_[p2] = p1;
        } else if (rank_[p1] < rank_[p2]) {
            par_[p1] = p2;
        } else {
            par_[p1] = p2;
            rank_[p2] += 1;
        }
        return true;
    }
};

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        UnionFind t(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
        for (const auto& v : edges) {
            min_heap.push({v[2], v[0], v[1]});
        }
        int total = 0;
        int e = 0;
        while (!min_heap.empty()) {
            vector<int> v = min_heap.top();
            min_heap.pop();
            if (t._union(v[1], v[2])) {
                // if (!check.contains(v[1])) check.insert(v[1]);
                // if (!check.contains(v[2])) check.insert(v[2]);
                total += v[0];
                e++;
                if (e == n-1) return total;
            }
        }
        return -1;
    }
};
