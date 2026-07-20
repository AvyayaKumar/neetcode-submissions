class Solution {
public:
    vector<vector<int>> visited, grid;
    int counter = 0;
    void floodfill(int r, int c) {
        if (min(r, c) < 0 || r >= grid.size() || c >= grid[0].size()) return;
        if (visited[r][c] == 1 || grid[r][c] == 0) return;
        visited[r][c] = 1;
        counter++;
        floodfill(r+1, c);
        floodfill(r, c+1);
        floodfill(r-1, c);
        floodfill(r, c-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid; vector<int> t;
        for (int i : grid[0]) t.push_back(0);
        for (int i = 0; i < grid.size(); i++) visited.push_back(t);
        int greatest_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    counter = 0;
                    floodfill(i, j);
                    greatest_area = max(greatest_area, counter);
                }
            }
        }
        return greatest_area;
    }
};
