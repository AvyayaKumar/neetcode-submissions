class Solution {
public:
    vector<int> memo;
    vector<vector<int>> memoi;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        for (int i = 0; i <= 1; i++) memoi.push_back(memo);
        return dfs(nums, 0, 0);
    }
    int dfs(vector<int>& nums, int i, int takeFirst) {
        if (i >= nums.size()) return 0;
        if (memoi[takeFirst][i] != -1) return memoi[takeFirst][i];
        if (i == nums.size()-1 && takeFirst == 1) return 0;
        if (i == 0) {
            memoi[takeFirst][i] = max(nums[i] + dfs(nums, i+2, 1), dfs(nums, i+1, 0));
        } else {
            memoi[takeFirst][i] = max(nums[i] + dfs(nums, i+2, takeFirst), dfs(nums, i+1, takeFirst));
        }
        return memoi[takeFirst][i];
    }
};
