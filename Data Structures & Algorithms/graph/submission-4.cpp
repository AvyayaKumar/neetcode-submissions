class Graph {
public:
    unordered_map<int, unordered_set<int>> g;
    Graph() {

    }

    bool betterhasPath(int src, int dst, unordered_set<int>& vsted) {
        if (src == dst) return true;
        if (g[src].size() == 0) return false;
        vsted.insert(src);
        for (auto it = g[src].begin(); it != g[src].end(); it++) {
            if (vsted.find(*it) != vsted.end()) continue;
            if (betterhasPath(*it, dst, vsted)) return true;
        }
        
        return false;
    }

    void addEdge(int src, int dst) {
        if (g.find(src) == g.end()) g[src] = {};
        if (g.find(dst) == g.end()) g[dst] = {};
        g[src].insert(dst);
    } 

    bool removeEdge(int src, int dst) {
        if (g.find(src) == g.end()) return false;
        if (g[src].find(dst) == g[src].end()) return false;
        g[src].erase(dst); return true;
    }

    bool hasPath(int src, int dst) {
        unordered_set<int> tm;
        return betterhasPath(src, dst, tm);
    }
};
