class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.length(), -1);
        unordered_set<string> dict;
        for (string i : wordDict) {
            dict.insert(i);
        }
        if (dp(s, dict, 0) == 1) return true;
        return false;
    }
    int dp(string s, unordered_set<string>& wordDict, int j) {
        int i = j;
        if (i >= s.length()) return 1;
        if (memo[i] != -1) return memo[i];
        string w = "";
        while (i < s.length()) {
            w += s[i];
            if (wordDict.contains(w)) {
                if (dp(s, wordDict, i+1) != 0) {
                    return 1;
                } else {
                    memo[i] = 0;
                }
            }
            i++;
        }
        memo[j] = 0;
        return memo[j];
    }
};
