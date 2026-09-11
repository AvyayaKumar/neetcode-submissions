class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj_list;
        for (const auto& v : prerequisites) {
            adj_list[v[0]].push_back(v[1]);
        }
        unordered_set<int> visited;
        unordered_set<int> path;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, visited, path, adj_list)) return {};
        }
        return ans;
    }
    bool dfs(int node, unordered_set<int>& visited, unordered_set<int>& path, unordered_map<int, vector<int>>& adj_list) {
        if (path.contains(node)) return false;
        if (visited.contains(node)) return true;
        path.insert(node);
        visited.insert(node);
        for (int neighbor : adj_list[node]) {
            if (!dfs(neighbor, visited, path, adj_list)) return false;
        }
        path.erase(node);
        ans.push_back(node);
        return true;
    }
};
