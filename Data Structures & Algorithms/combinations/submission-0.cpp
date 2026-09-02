class Solution {
public:
    int n, k;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n_inp, int k_inp) {
        n = n_inp;
        k = k_inp;
        helper(1, {});
        return ans;
    }
    void helper(int i, vector<int> curr) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if (i > n) return;
        for (int j = i; j <= n; j++) {
            curr.push_back(j);
            helper(j+1, curr);
            curr.pop_back();
        }
    }
};