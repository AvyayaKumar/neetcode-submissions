class Solution {
public:
    int target;
    vector<int> nums;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums_inp, int target_inp) {
        nums = nums_inp;
        target = target_inp;
        helper(0, 0, {});
        return ans;
    }
    void helper(int i, int curr_sum, vector<int> curr_set) {
        if (i >= nums.size()) return;
        if (curr_sum > target) return;
        if (curr_sum == target) {
            ans.push_back(curr_set);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            curr_sum += nums[j];
            curr_set.push_back(nums[j]);
            helper(j, curr_sum, curr_set);
            curr_sum -= nums[j];
            curr_set.pop_back();
        }
    }
};
