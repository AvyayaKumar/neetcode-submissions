class Solution {
public:
    vector<string> ans;
    string digits;
    vector<string> letterCombinations(string digits_inp) {
        digits = digits_inp;
        if (digits.size() == 0) return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        helper(0, "", mp);
        return ans;
    }
    void helper(int i, string curr, unordered_map<char, string>& mp) {
        if (i == digits.length()) {
            ans.push_back(curr);
            return;
        }
        string poss = mp[digits[i]];
        for (int j = 0; j < poss.length(); j++) {
            curr.push_back(poss[j]);
            helper(i+1, curr, mp);
            curr.pop_back();
        }
    }
};
