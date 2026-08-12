class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum(nums.size());
        int total = 0;
        for (int i : nums) {
            total += i;
            leftSum.push_back(total);
        }
        total = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            total += nums[i];
            rightSum[i] = total;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum[i] == rightSum[i]) return i;
        }
        return -1;
    }
};