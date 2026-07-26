class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> currRow(n, 0); currRow[n-1] = 1;
            for (int i = n-2; i >= 0; i--) {
                currRow[i] = currRow[i+1]+prevRow[i];
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
};
