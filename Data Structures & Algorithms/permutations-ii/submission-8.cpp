class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            if (!mp.contains(i)) mp[i] = 1;
            else mp[i]++;
        }
        helper(mp, {});
        return ans;
    }
    void helper(unordered_map<int, int> mp, vector<int> curr_set) {
        bool done = true;
        for (auto i : mp) {
            if (i.second != 0) {
                curr_set.push_back(i.first);
                mp[i.first]--;
                helper(mp, curr_set);
                curr_set.pop_back();
                mp[i.first]++;
                done = false;
            }
        }
        if (done) ans.push_back(curr_set);
    }
};