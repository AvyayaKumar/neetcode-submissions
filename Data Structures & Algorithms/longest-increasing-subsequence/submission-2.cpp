class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        for (int i = nums.size()-1; i >= 0; i--) {
            int m = 0;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    m = max(m, memo[j]);
                }
            }
            memo[i] = m+1;
        }
        int n = 0;
        for (int i : memo) {
            n = max(n, i);
        }
        return n;
    }
};
