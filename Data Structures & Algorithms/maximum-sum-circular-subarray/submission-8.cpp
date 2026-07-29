class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0]; int globalMin = nums[0]; int currMax = 0; int currMin = 0; int total = 0;
        for (int i : nums) {
            total += i;
            currMax = max(currMax + i, i);
            currMin = min(currMin + i, i);
            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }
        return (globalMax < 0) ? globalMax : max(globalMax, total-globalMin);
    }
};