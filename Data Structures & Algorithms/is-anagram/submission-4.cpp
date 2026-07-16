class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sm; unordered_map<char, int> st;
        for (int i = 0; i < s.length(); i++) {
            if (sm.find(s[i]) == sm.end()) {
                sm[s[i]] = 1;
            } else {
                sm[s[i]]++;
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (st.find(t[i]) == st.end()) {
                st[t[i]] = 1;
            } else {
                st[t[i]]++;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            // cout << sm.count(s[i]) << " " << st.count(s[i]) << endl;
            if (sm[s[i]] != st[s[i]]) {
                return false;
            }
        }
        for (int i = 0; i < t.length(); i++) {
            // cout << sm.count(s[i]) << " " << st.count(s[i]) << endl;
            if (sm[t[i]] != st[t[i]]) {
                return false;
            }
        }
        return true;
    }
};
