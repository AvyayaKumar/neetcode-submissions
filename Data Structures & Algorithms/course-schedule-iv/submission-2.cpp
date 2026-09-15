class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj_list;
        for (const auto& a : prerequisites) {
            adj_list[a[0]].push_back(a[1]);
        }
        unordered_map<int, unordered_set<int>> post_cls;
        for (int i = 0; i < numCourses; i++) {
            dfs(i, adj_list, post_cls);
        }
        vector<bool> ans;
        for (const auto& q : queries) {
            if (post_cls[q[0]].contains(q[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
    unordered_set<int> dfs(int node, unordered_map<int, vector<int>>& adj_list, unordered_map<int, unordered_set<int>>& post_cls) {
        unordered_set<int> res;
        if (post_cls.contains(node)) {
            res = post_cls[node];
            res.insert(node);
            return res;
        }
        for (int nbor : adj_list[node]) {
            unordered_set<int> add = dfs(nbor, adj_list, post_cls);
            for (const auto& x : add) {
                res.insert(x);
            }
        }
        post_cls[node] = res;
        res.insert(node);
        return res;
                
    }
};