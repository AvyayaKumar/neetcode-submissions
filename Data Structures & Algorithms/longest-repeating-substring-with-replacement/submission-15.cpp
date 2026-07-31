class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest_substring = 0;
        for (int l = 0; l < s.length(); l++) {
            int r = l;
            int right = l; int left = l;
            int subs = 0;
            int inarow = l;
            bool inaro = true;
            while (r < s.length()) {
                if (s[r] != s[l]) {
                    inaro = false;
                    subs++;
                }
                if (subs > k) {
                    break;
                }
                if (inaro) inarow++;
                right = r;
                r++;
            }
            if (right == s.length()-1 && subs < k) {
                while (left > 0 && subs < k) {
                    left--; subs++;
                }
            }
            cout << left << " " << right << " " << subs << endl;
            longest_substring = max(longest_substring, right-left+1);
            if (inarow > l+1) l = inarow-1;
            
        }
        return longest_substring;
    }
};
