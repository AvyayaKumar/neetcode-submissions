class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0, {});
        return ans;
    }
    void helper(vector<int>& nums, int i, vector<int> curr_set) {
        if (i >= nums.size()) {
            ans.push_back(curr_set);
            return;
        }
        int iter = i;
        while (i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        for (int j = iter; j <= i; j++) {
            curr_set.push_back(nums[j]);
            helper(nums, i+1, curr_set);
        }
        for (int j = iter; j <= i; j++) {
            curr_set.pop_back();
        }
        helper(nums, i+1, curr_set);
        
    }
};
