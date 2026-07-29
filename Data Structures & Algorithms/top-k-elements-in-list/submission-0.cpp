class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tracker;
        for (int& i : nums) {
            tracker[i] += 1;
        }
        unordered_map<int, vector<int>> tracker2;
        for (auto& i : tracker) {
            tracker2[i.second].push_back(i.first);
        }
        vector<int> ans;
        int iterator = 0;
        for (int i = nums.size(); i >= 0; i--) {
            if (tracker2.find(i) != tracker2.end()) {
                for (auto j : tracker2[i]) {
                    ans.push_back(j);
                    iterator++;
                    if (iterator == k) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
