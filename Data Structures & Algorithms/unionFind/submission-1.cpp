class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        int curr = x;
        while (curr != parent[curr]) {
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int p1 = find(x); int p2 = find(y);
        if (p1 == p2) return false;

        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p2] < rank[p1]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;
    }

    int getNumComponents() {
        int ans = 0;
        for (auto i : parent) {
            if (i.first == i.second) ans++;
        }
        return ans;
    }
};
