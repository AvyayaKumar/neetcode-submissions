class UnionFind {
public:
    unordered_map<string, string> par_;
    unordered_map<string, int> rank_;

    UnionFind(vector<vector<string>>& accounts) {
        for (int i = 0; i < accounts.size(); i++) {
            string blank = to_string(i);
            par_[blank] = blank;
            rank_[blank] = 1;
            for (int j = 1; j < accounts[i].size(); j++) {
                string word = accounts[i][j];
                par_[word] = word;
                rank_[word] = 1;
            }
        }
    }

    string find(const string& n) {
        string p = par_[n];
        while (p != par_[p]) {
            par_[p] = par_[par_[p]];
            p = par_[p];
        }
        return p;
    }

    bool _union(string& n1, string& n2) {
        string p1 = find(n1); string p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank_[p1] > rank_[p2]) {
            par_[p2] = p1;
        } else if (rank_[p1] < rank_[p2]) {
            par_[p1] = p2;
        } else {
            par_[p2] = p1;
            rank_[p1] += 1;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind x(accounts);
        
        for (int i = 0; i < accounts.size(); i++) {
            string name = to_string(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                x._union(name, accounts[i][j]);
            }
        }


        unordered_map<string, vector<string>> temp;
        unordered_map<string, unordered_set<string>> temp2;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string parent = x.find(accounts[i][j]);
                if (!temp2[parent].contains(accounts[i][j])) {
                    temp[parent].push_back(accounts[i][j]);
                    temp2[parent].insert(accounts[i][j]);
                }
                
            }
        }

        vector<vector<string>> ans;
        for (auto i : temp) {
            vector<string> ans_temp;
            ans_temp.push_back(accounts[stoi(i.first)][0]);
            vector<string> y = i.second;
            sort(y.begin(), y.end());
            for (auto j : y) {
                ans_temp.push_back(j);
            }
            ans.push_back(ans_temp);
        }

        return ans;
    }
};