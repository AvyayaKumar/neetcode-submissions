class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        // vector<vector<int>> memo(s.length(), vector<int>(s.length(), 0));
        queue<pair<int, int>> palindromes;
        for (int i = 0; i < s.length(); i++) {
            // memo[i][i] = 1;
            palindromes.push({i, i});
            // res++;
        }
        for (int i = 0; i+1 < s.length(); i++) {
            if (s[i] == s[i+1]) {
                palindromes.push({i, i+1});
                // res++;
            }
        }
        while (!palindromes.empty()) {
            pair<int, int> curPalindrome = palindromes.front();
            palindromes.pop();
            int l = curPalindrome.first;
            int r = curPalindrome.second;
            if (l-1 >= 0 && r+1 < s.length() && s[l-1] == s[r+1]) {
                palindromes.push({l-1, r+1});
            }
            res++;
            // cout << s.substr(l, r-l+1) << " ";
        }
        return res;
    }
};
