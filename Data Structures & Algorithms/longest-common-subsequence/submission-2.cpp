class Solution {
public:
    int dp(string& t1, string& t2, int i1, int i2, vector<vector<int>>& memo) {
        if (i1 == t1.size() || i2 == t2.size()) return 0;
        if (memo[i1][i2] != -1) return memo[i1][i2];
        if (t1[i1] == t2[i2])
            return memo[i1][i2] = 1 + dp(t1, t2, i1+1, i2+1, memo);
        return memo[i1][i2] = max(dp(t1, t2, i1+1, i2, memo), dp(t1, t2, i1, i2+1, memo));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length(), vector<int>(text2.length(), -1));
        return dp(text1, text2, 0, 0, memo);
    }
};
