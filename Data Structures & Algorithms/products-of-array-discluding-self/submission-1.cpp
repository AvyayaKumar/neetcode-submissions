class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prodSum;
        vector<int> zeroes;
        int n = nums.size();
        int total = 1;
        prodSum.push_back(total);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zeroes.push_back(i);
            else {
                total *= nums[i];
            }   
            prodSum.push_back(total);
        }
        if (zeroes.size() > 1) return vector<int>(n, 0);
        int lpointer;
        if (zeroes.size() == 1) lpointer = zeroes[0];
        vector<int> output;
        // for (int i : prodSum) cout << i << " ";
        for (int i = 1; i < n+1; i++) {
            if (zeroes.size() == 1 && lpointer == i-1) {
                output.push_back(prodSum[n]);
            } else if (zeroes.size() == 1) {
                output.push_back(0);
            } else {
                output.push_back((prodSum[n] / prodSum[i]) * prodSum[i-1]);
            }
        }
        return output;
    }
};
