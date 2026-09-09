class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
            par_[i] = i;
            rank_[i] = 0;
        }
    }

    // Find parent of n, with path compression.
    int find(int n) {
        int p = par_[n];
        while (p != par_[p]) {
            par_[p] = par_[par_[p]];
            p = par_[p];
        }
        return p;
    }

    // Union by height / rank.
    // Return false if already connected, true otherwise.
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
    int manDist(int xi, int yi, int xj, int yj) {
        return abs(xi-xj) + abs(yi-yj);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, pair<int, int>> cord;
        int i = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
        for (const vector<int>& v : points) {
            cord[i] = {v[0], v[1]};
            i++;
        }
        for(int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                min_heap.push({manDist(points[i][0], points[i][1], points[j][0], points[j][1]), i, j});
            }
        }
        UnionFind tree(n);
        int total = 0;
        // unordered_set<int> visited;
        int e = 0;
        while (!min_heap.empty()) {
            vector<int> v = min_heap.top();
            min_heap.pop();
            if (tree._union(v[1], v[2])) {
                total += v[0];
                e++;
                if (e == n-1) return total;
            }
        }
        return 0;
    }
};
