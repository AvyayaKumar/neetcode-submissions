class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.length()+1, -1);
        memo[s.length()] = 1;
        return dfs(memo, s, 0);
    }
    int dfs(vector<int>& memo, string& s, int i) {
        if (memo[i] != -1) return memo[i];
        if (s[i] == '0') return 0;

        int res = dfs(memo, s, i+1);
        if (i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6' && s[i+1] >= '0'))) {
            res += dfs(memo, s, i+2);
        }
        memo[i] = res;
        return res;
    }
};
