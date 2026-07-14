class Solution {
public:
    vector<vector<int>> ans;

    void recurSet(vector<int>& nums, vector<int> currArr, int curr_index) {
        if (curr_index == nums.size()) {
            ans.push_back(currArr);
        } else {
            recurSet(nums, currArr, curr_index+1);
            currArr.push_back(nums[curr_index]);
            recurSet(nums, currArr, curr_index+1);
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp; temp.push_back(1); temp.push_back(2);
        vector<int> temp2;
        recurSet(nums, temp2, 0);
        return ans;
    }
};
