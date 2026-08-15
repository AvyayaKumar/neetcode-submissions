class Solution {
public:
    int countSubstrings(const string& s) {
        int n = s.size(), res = 0;
        for (int c = 0; c < 2 * n - 1; c++) {
            int l = c / 2;
            int r = l + (c & 1);          // even c -> odd-length, odd c -> even-length
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};