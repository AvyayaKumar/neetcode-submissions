class Solution {
public:
    void floodfill(vector<vector<char>>& grid, int r, int c) {
        if (min(r, c) < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') return;
        grid[r][c] = '0';
        floodfill(grid, r+1, c);
        floodfill(grid, r-1, c);
        floodfill(grid, r, c+1);
        floodfill(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++; floodfill(grid, i, j);
                }
            }
        }
        return ans;
    }
};
