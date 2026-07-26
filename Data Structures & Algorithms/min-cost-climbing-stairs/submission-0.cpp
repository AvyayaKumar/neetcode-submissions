class Solution {
public:
    unordered_map<int, int> stairs;
    int dfs(vector<int>& cost, int curr_step) {
        if (curr_step >= cost.size()) return 0;
        if (stairs.find(curr_step) != stairs.end()) return stairs[curr_step];
        stairs[curr_step] = min(cost[curr_step]+dfs(cost, curr_step+1), cost[curr_step]+dfs(cost, curr_step+2));
        return stairs[curr_step];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(cost, 0), dfs(cost, 1));
    }
};
