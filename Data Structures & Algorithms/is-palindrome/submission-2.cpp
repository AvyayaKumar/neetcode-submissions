class Solution {
public:
    bool valid(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        else if (c >= 'A' && c <= 'Z') {
            return true;
        }
        else if (c >= '0' && c <= '9') {
            return true;
        }
        else {
            return false;
        }
    }
    bool isPalindrome(string s) {
        int l = 0; int r = s.length() -1;
        for (auto& x : s) {
            x = tolower(x);
        }
        while (l <= r) {
            while (valid(s[l]) == false && l < s.length()) {
                l++;
                continue;
            }
            while (valid(s[r]) == false && r >= 0) {
                r--;
                continue;
            }
            if (s[l] != s[r]) {
                cout << l << " " << r << " " << s.length()-1;
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
