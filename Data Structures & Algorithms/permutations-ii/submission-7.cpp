class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms = {{}};
        for (int n : nums) {
            vector<vector<int>> next_perms;
            for (const vector<int>& v : perms) {
                for (int i = 0; i <= (int)v.size(); i++) {
                    vector<int> w = v;
                    w.insert(w.begin() + i, n);
                    next_perms.push_back(w);
                    if (i < (int)v.size() && v[i] == n) break;
                }
            }
            perms = next_perms;
        }
        return perms;
    }
};