class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<pair<int, int>>> adj_list;
        for (const vector<int>& v : edges) {
            adj_list[v[0]].push_back({v[1], v[2]});
            adj_list[v[1]].push_back({v[0], v[2]});
        }
        int total = 0;
        unordered_set<int> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
        //let's use the very first edge - u1, v1, w1 - and start from u1
        int start_node = edges[0][0];
        min_heap.push({0, start_node});
        while (!min_heap.empty()) {
            vector<int> t = min_heap.top();
            min_heap.pop();
            int w = t[0];
            int v = t[1];
            if (!visited.contains(v)) {
                visited.insert(v);
                total += w;
                vector<pair<int, int>> neighbors = adj_list[v];
                for (pair<int, int> n : neighbors) {
                    if (!visited.contains(n.first)) {
                        min_heap.push({n.second, n.first});
                    }
                }
            }
        }
        if (visited.size() == n) return total;
        return -1;
    }
};

