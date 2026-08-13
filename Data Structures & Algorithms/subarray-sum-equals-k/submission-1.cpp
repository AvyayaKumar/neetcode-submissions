class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum;
        unordered_map<int, vector<int>> indexing;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            prefixSum.push_back(total);
            indexing[total].push_back(i);
        }
        // for (auto i : indexing) {
        //     cout << i.first << ": ";
        //     for (int j : indexing[i.first]) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int reqNum = prefixSum[i]-k;
            if (reqNum == 0) {
                // cout << 0 << " " << i << endl;
                if (indexing.find(0) != indexing.end()) {
                    for (int j : indexing[reqNum]) {
                        if (j < i) res++;
                    }
                }
                res++;
            }
            else if (indexing.find(reqNum) != indexing.end()) {
                for (int j : indexing[reqNum]) {
                    if (j < i) {
                        // cout << i << " " << j << endl;
                        res++;
                    }
                }
            }
            // cout << endl;
        }
        return res;
    }
};