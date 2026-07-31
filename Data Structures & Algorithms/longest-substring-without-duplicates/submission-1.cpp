class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //goal: to find the longest substring without duplicate characters
        //issue: if we were to iterate with a variable sliding window, how would we confirm
        //that the characters in the middle are not secretly duplicated
        //oh bro im dumb just use an unordered_set it's literally O(1) search and insert 
        unordered_set<char> substring;
        int l = 0; int longest_substring = 0;
        for (int r = 0; r < s.length(); r++) {
            if (substring.find(s[r]) == substring.end()) {
                substring.insert(s[r]);
                if (r-l+1 >= longest_substring) {
                    cout << l << " " << r << endl;
                }
                longest_substring = max(longest_substring, r-l+1);
            } else {
                while (substring.find(s[r]) != substring.end()) {
                    substring.erase(s[l]);
                    l++;
                }
                substring.insert(s[r]);
                // cout << "else " << l << " " << r << endl;
            }
        }
        return longest_substring;
    }
};
