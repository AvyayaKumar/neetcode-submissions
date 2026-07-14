class Solution {
public:
    vector<vector<int>> ans;

    void recurComSum(vector<int>& nums, vector<int> currArr, int currSum, int target) {
        if (currSum == target) {
            // vector<int> currArr2 = currArr;
            // sort(currArr2.begin(), currArr2.end());
            // auto it = find(ans.begin(), ans.end(), currArr2);
            // if (it == ans.end()) {
                ans.push_back(currArr);
            // }
        }
        else if (currSum < target) {
            for (int i = 0; i < nums.size(); i++) {
                if (currSum+nums[i] <= target) {
                    currArr.push_back(nums[i]);
                    recurComSum(nums, currArr, currSum+nums[i], target);
                    currArr.pop_back();
                }
            }
        }
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        recurComSum(nums, {}, 0, target);
        for (int i = 0; i < ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
