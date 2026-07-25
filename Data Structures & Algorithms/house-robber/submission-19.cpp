class Solution {
public: 
    unordered_map<int, int> max_value_index;
    int recursion(vector<int>& nums, int start_index) {
        if (start_index >= nums.size()) return 0;
        if (max_value_index.find(start_index) != max_value_index.end()) return max_value_index[start_index];
        max_value_index[start_index] = max(recursion(nums, start_index+1), nums[start_index]+recursion(nums, start_index+2));
        return max_value_index[start_index];
    }

    int rob(vector<int>& nums) {
        return recursion(nums, 0);
    }
};
