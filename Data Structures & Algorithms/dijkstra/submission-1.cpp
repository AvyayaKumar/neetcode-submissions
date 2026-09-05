class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adjlist;
        unordered_map<int, int> shortest;
        int total = 0;
        for (int i = 0; i < n; i++) {
            adjlist[i] = {};
            shortest[i] = -1;
            total++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;
        for (int i = 0; i < edges.size(); i++) {
            adjlist[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        heap.push({0, src});
        while (!heap.empty()) {
            pair<int, int> heap_top = heap.top();
            heap.pop();
            int node = heap_top.second;
            int dist = heap_top.first;
            if (shortest[node] == -1) {
                shortest[node] = dist;
                total--;
                vector<pair<int, int>> neighbors = adjlist[node];
                for (pair<int, int> i : neighbors) {
                    heap.push({dist+i.second, i.first});
                }
            }
            if (total == 0) break;
        }
        return shortest;

    }
};
