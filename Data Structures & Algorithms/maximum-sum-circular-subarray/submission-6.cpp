class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];

        for (int i = 0; i < n; i++) {
            int curSum = 0;
            for (int j = i; j < i + n; j++) {
                curSum += nums[j % n];
                res = max(res, curSum);
            }
        }

        return res;
    }
};