class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& currCombo) {
        if (target == 0) {
            result.push_back(currCombo);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) break; // sorted ascending — nothing further can work either
            if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicate sibling at this depth
            currCombo.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, currCombo);
            currCombo.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currCombo;
        backtrack(candidates, target, 0, currCombo);
        return result;
    }
};