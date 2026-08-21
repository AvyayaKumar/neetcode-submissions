class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;
        for (int num : nums) {
            int tmp = num*curMax;
            curMax = max(max(num, num*curMax), num*curMin);
            curMin = min(min(num, tmp), num*curMin);
            res = max(res, curMax);
        }
        return res;
    }
};
