class Solution {
public:
    int rows, cols;
    
    int memoization(vector<vector<int>>& obstacleGrid, int r, int c, vector<vector<int>>& dp) {
        if (r >= rows || c >= cols) return 0;
        if (r == rows-1 && c == cols-1) return 1;
        if (obstacleGrid[r][c] == 1) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        dp[r][c] = (memoization(obstacleGrid, r+1, c, dp) + memoization(obstacleGrid, r, c+1, dp));
        return dp[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size(); cols = obstacleGrid[0].size();
        if (rows == 1 && cols == 1) {
            if (obstacleGrid[0][0] == 0) return 1;
            return 0;
        }
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return memoization(obstacleGrid, 0, 0, dp);
    }
};