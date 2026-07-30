class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        queue<pair<int, int>> even;
        queue<pair<int, int>> odd;
        if (s.size() >= 2) {
            for (int i = 0; i < s.length()-1; i++) {
                if (s[i] == s[i+1]) {
                    even.push({i, i+1});
                }
            }
        }
        if (s.size() >= 3) {
            for (int i = 0; i < s.length()-2; i++) {
                if (s[i] == s[i+2]) {
                    odd.push({i, i+2});
                }
            }
        }
        if (even.size() == 0 && odd.size() == 0) {
            return s.substr(0, 1);
        }
        int leneven = 2;
        int leven = 0;
        bool waseven = false;
        while (!even.empty()) {
            bool didithappen = false;
            waseven = true;
            int fuck = even.size();
            for (int i = 0; i < fuck; i++) {
                pair<int, int> yaya = even.front(); even.pop(); int l = yaya.first; int r = yaya.second;
                leven = l;
                if (l-1 >= 0 && r+1 < s.length()) {
                    if (s[l-1] == s[r+1]) {
                        even.push({l-1, r+1});
                        didithappen = true;
                    }
                }
            }
            if (didithappen) {
                leneven+=2;
            }
        }
        int lenodd = 3;
        int lodd = 0;
        bool wasodd= false; 
        while (!odd.empty()) {
            bool didithappen = false;
            wasodd = true;
            int fuck = odd.size();
            for (int i = 0; i < fuck; i++) {
                pair<int, int> yaya = odd.front(); odd.pop(); int l = yaya.first; int r = yaya.second;
                lodd = l;
                if (l-1 >= 0 && r+1 < s.length()) {
                    if (s[l-1] == s[r+1]) {
                        // cout << l-1 << " " << r+1 << endl;
                        odd.push({l-1, r+1});
                        didithappen = true;
                    }
                }
            }
            if (didithappen) {
                lenodd+=2;
            }
        }

        if (waseven && wasodd) {
            cout << leneven << " " << lenodd;
            return (leneven > lenodd) ? s.substr(leven, leneven) : s.substr(lodd, lenodd);
        } else if (waseven) {
            cout << "waseven";
            return s.substr(leven, leneven);
        } else {
            cout << "wasodd";
            return s.substr(lodd, lenodd);
        }
    }
};
