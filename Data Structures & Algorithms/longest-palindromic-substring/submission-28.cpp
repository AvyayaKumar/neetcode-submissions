class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        if (s[i] != s[j]) return false;
        if (j <= i) return true;
        return isPalindrome(s, i+1, j-1);
    }
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int len = -1;
        int l = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s, i, j)) {
                    if (j-i+1 > len) {
                        len = j-i+1;
                        l = i;
                    }
                }
            }
            if (len >= s.length()-i) {
                return s.substr(l, len);
            }
        }
        return s.substr(l, len);
    }
};
