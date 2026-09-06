class Solution {
public:
    int manDist(int xi, int yi, int xj, int yj) {
        return abs(xi-xj) + abs(yi-yj);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, pair<int, int>> nodes;
        int it = 0;
        for (const auto& v : points) {
            nodes[it] = {v[0], v[1]};
            it++;
        }
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        int total = 0;
        min_heap.push({0, 0});
        while (!min_heap.empty()) {
            pair<int, int> p = min_heap.top();
            min_heap.pop();
            int cost = p.first;
            if (!visited.contains(p.second)) {
                visited.insert(p.second);
                total += cost;
                pair<int, int> point = nodes[p.second];
                for (int i = 0; i < points.size(); i++) {
                    if (!visited.contains(i)) {
                        min_heap.push({manDist(point.first, point.second, nodes[i].first, nodes[i].second), i});
                    }
                }
            }
        }
        return total;
    }
};
