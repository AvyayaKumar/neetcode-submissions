class Solution {
public:
    vector<int> ans;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //so the only way that we can't finish the courses is if there's a cycle - otherwise we're able to take everything
        unordered_map<int, vector<int>> adj_list;
        for (const auto& a : prerequisites) {
            adj_list[a[0]].push_back(a[1]);
            // cout << a[0] << " " << a[1] << endl;
        }
        unordered_set<int> visited;
        unordered_set<int> path;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj_list, visited, path)) return false;
        }
        return true;
    }
    bool dfs(int node, unordered_map<int, vector<int>>& adj_list, unordered_set<int>& visited, unordered_set<int>& path) {
        if (path.contains(node)) {
            cout << node << endl;
            return false;
        }
        if (visited.contains(node)) return true;
        // cout << node << "passed" << endl;
        path.insert(node);
        visited.insert(node);
        if (adj_list.contains(node)) {
            for (int neighbor : adj_list[node]) {
                if (!dfs(neighbor, adj_list, visited, path)) return false;
            }
        }
        path.erase(node);
        // ans.push_back(node);
        return true;
    }
};
