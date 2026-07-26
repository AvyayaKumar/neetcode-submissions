class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (string i : strs) {
            string copy = i;
            sort(copy.begin(), copy.end());
            if (m.find(copy) != m.end()) {
                m[copy].push_back(i);
            } else {
                m[copy] = {i};
            }
        }
        vector<vector<string>> ans;
        for (auto it : m) {
            ans.push_back(it.second);
        } 
        return ans;
    }
};
