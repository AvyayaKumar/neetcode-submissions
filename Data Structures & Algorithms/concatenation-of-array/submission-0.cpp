class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for (int loop = 0; loop < 2; loop++) {
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};