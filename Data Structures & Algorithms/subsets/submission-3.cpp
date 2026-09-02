class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0, {});
        return ans;
    }
    void helper(vector<int> nums, int i, vector<int> curr_set) {
        if (i == nums.size()) {
            ans.push_back(curr_set);
            return;
        }
        helper(nums, i+1, curr_set);
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] != nums[i]) break;
            curr_set.push_back(nums[j]);
            helper(nums, j+1, curr_set);
        }
        
    }
};
