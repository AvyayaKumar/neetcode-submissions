class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj_list;
        for (const auto& edge : edges) adj_list[edge[0]].push_back(edge[1]);
        unordered_set<int> visited;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            unordered_set<int> path;
            if (dfs(i, visited, path, adj_list, ans) == -1) return {};
            // cout << dfs(i, visited, path, adj_list, ans) << endl;
        }
        vector<int> new_ans;
        for (int i = ans.size()-1; i >= 0; i--) {
            new_ans.push_back(ans[i]);
        }
        return new_ans;

    }
    
    int dfs(int node, unordered_set<int>& visited, unordered_set<int>& path, unordered_map<int, vector<int>>& adj_list, vector<int>& ans) {
        if (path.contains(node)) return -1;
        if (visited.contains(node)) return 0;
        visited.insert(node);
        path.insert(node);
        for (int neighbor : adj_list[node]) {
            if (dfs(neighbor, visited, path, adj_list, ans) == -1) return -1;
            path.clear();
        }
        ans.push_back(node);
        return 1;
    }
};
