class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] != "+" && operations[i] != "D" && operations[i] != "C") {
                scores.push_back(stoi(operations[i])); 
                // cout << operations[i] << " ";
            // }
            } else if (operations[i] == "+") {
                scores.push_back(scores[scores.size()-1]+scores[scores.size()-2]);
            } else if (operations[i] == "D") {
                scores.push_back(scores[scores.size()-1]*2);
            } else {
                scores.pop_back();
            }
        }
        int ans = 0;
        for (int i = 0; i < scores.size(); i++) {
            ans += scores[i];
        }
        return ans;
    }
};