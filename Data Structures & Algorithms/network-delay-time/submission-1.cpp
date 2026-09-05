class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjlist;
        unordered_map<int, int> shortest;

        for (int i = 1; i <= n; i++) {
            adjlist[i] = {};
            shortest[i] = -1;
        }
        
        for (int i = 0; i < times.size(); i++) {
            adjlist[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        heap.push({0, k});
        while (!heap.empty()) {
            int node = heap.top().second;
            int dist = heap.top().first;
            heap.pop();
            if (shortest[node] == -1) {
                shortest[node] = dist;
                vector<pair<int, int>> neighbors = adjlist[node];
                for (pair<int, int> p : neighbors) {
                    heap.push({dist+p.second, p.first});
                }
            }
        }
        int m = 0;
        for (auto i : shortest) {
            m = max(m, i.second);
            if (i.second == -1) return -1;
        }
        // if (m == 1) return -1;
        return m;
    }
};
