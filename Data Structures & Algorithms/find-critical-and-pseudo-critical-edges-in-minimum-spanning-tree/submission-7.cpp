class UnionFind {
public:
    vector<int> par;
    vector<int> rank;
    UnionFind(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        rank.resize(n, 0);
    }

    int find(int node) {
        int p = par[node];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool _union(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if (p1 == p2) return false;

        if (rank[p1] < rank[p2]) {
            par[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        } else {
            par[p1] = p2;
            rank[p2]++;
        }
        return true;
    }
};


class Solution {
public:
    pair<unordered_set<int>, int> kruskal_mst(int n, vector<vector<int>>& edges, int include) {
        unordered_set<int> mst;
        unordered_set<int> blank;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
        UnionFind tree(n);
        int e = 0;
        int total = 0;

        for (int i = 0; i < edges.size(); i++) {
            if (i == include) {
                total += edges[i][2];
                e++;
                mst.insert(i);
                tree._union(edges[i][0], edges[i][1]);
                continue;
            }
            const vector<int>& v = edges[i];
            min_heap.push({v[2], v[0], v[1], i});
        }
        
        while (!min_heap.empty()) {
            vector<int> edge = min_heap.top();
            min_heap.pop();
            if (tree._union(edge[1], edge[2])) {
                total += edge[0];
                e++;
                mst.insert(edge[3]);
                if (e == n-1) return {mst, total};
            }
        }
        
        return {blank, -1};
    }

    pair<unordered_set<int>, int> kruskal_mst_skip(int n, vector<vector<int>>& edges, int include) {
        unordered_set<int> mst;
        unordered_set<int> blank;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
        UnionFind tree(n);
        int e = 0;
        int total = 0;

        for (int i = 0; i < edges.size(); i++) {
            if (i == include) {
                continue;
            }
            const vector<int>& v = edges[i];
            min_heap.push({v[2], v[0], v[1], i});
        }
        
        while (!min_heap.empty()) {
            vector<int> edge = min_heap.top();
            min_heap.pop();
            if (tree._union(edge[1], edge[2])) {
                total += edge[0];
                e++;
                mst.insert(edge[3]);
                if (e == n-1) return {mst, total};
            }
        }
        
        return {blank, -1};
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        pair<unordered_set<int>, int> mst_edges = kruskal_mst_skip(n, edges, -1);
        vector<vector<int>> ans; ans.push_back({}); ans.push_back({});
        unordered_set<int> total_nodes;
        int default_mst = mst_edges.second;
        for (const auto& it : mst_edges.first) {
            total_nodes.insert(it);
        }

        for (int i = 0; i < edges.size(); i++) {
            if (total_nodes.contains(i)) continue;
            pair<unordered_set<int>, int> new_mst_edges = kruskal_mst(n, edges, i);
            if (new_mst_edges.second == default_mst) {
                for (const auto& j : new_mst_edges.first) {
                    if (!total_nodes.contains(j)) total_nodes.insert(j);
                }
            }
        }
        
        for (const auto& it : total_nodes) {
            pair<unordered_set<int>, int> new_mst_edges = kruskal_mst_skip(n, edges, it);
            if (new_mst_edges.second == default_mst) { //means that without this node, we can still make the mst
                ans[1].push_back(it);
            } else {
                ans[0].push_back(it);
            }
        }
        return ans;
    }
};