class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for (int i : nums) {
            currSum = max(currSum, 0);
            currSum += i;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
