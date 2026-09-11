class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj_list;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // unordered_map<int, vector<int>> adj_list;
        adj_list.resize(numCourses, {});        
        for (const auto& v : prerequisites) {
            adj_list[v[0]].push_back(v[1]);
        }
        // unordered_set<int> visited;
        vector<bool> visited(numCourses, 0);
        unordered_set<int> path;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, visited, path)) return {};
        }
        return ans;
    }
    bool dfs(int node, vector<bool>& visited, unordered_set<int>& path) {
        if (path.contains(node)) return false;
        if (visited[node]) return true;
        path.insert(node);
        visited[node] = true;
        for (int neighbor : adj_list[node]) {
            if (!dfs(neighbor, visited, path)) return false;
        }
        path.erase(node);
        ans.push_back(node);
        return true;
    }
};
