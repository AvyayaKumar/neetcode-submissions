class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (m.count(nums[i]) == 0) {
                m[nums[i]] = i;
            }  
        }
        for (int i = 0; i < n; i++) {
            if (m.count(target-nums[i]) != 0) {
                if (m[target-nums[i]] == i) {
                    bool ugh = false;
                    for (int j = 0; j < n; j++) {
                        if (nums[j] == nums[i] && j != i) {
                            ans.push_back(j); ans.push_back(i);
                            ugh = true;
                            break;
                        }
                    }
                    if (ugh) {
                        break;
                    }
                } else {
                    ans.push_back(m[target-nums[i]]); ans.push_back(i);
                    break;
                }
            } else {
                cout << "hey";
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
