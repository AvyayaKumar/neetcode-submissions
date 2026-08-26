class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i : nums) total += i;
        vector<vector<bool>> memo(total+1, vector<bool>(total+1, false));
        return dp(nums, 0, 0, 0, memo);
    }

    bool dp(vector<int>& nums, int sum1, int sum2, int i, vector<vector<bool>>& memo) {
        if (i >= nums.size()) return sum1 == sum2;
        if (memo[sum1][sum2]) return false;
        if (dp(nums, sum1+nums[i], sum2, i+1, memo)) return true;
        memo[sum1+nums[i]][sum2] = true;
        if (dp(nums, sum1, sum2+nums[i], i+1, memo)) return true;
        memo[sum1][sum2+nums[i]] = true;
        return false;
    }
};
