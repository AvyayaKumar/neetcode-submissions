class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        perms.push_back({});

        for (int n : nums) {
            vector<vector<int>> next_perms;
            for (vector<int> v : perms) {
                for (int i = 0; i <= v.size(); i++) {
                    v.insert(v.begin() + i, n);
                    next_perms.push_back(v);
                    v.erase(v.begin() + i);
                }
            }
            perms = next_perms;
        }
        return perms;
    }
};
