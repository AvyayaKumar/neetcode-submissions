class Solution {
public: 
    bool ch(int r, int c, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        if (min(r, c) >= 0 && r < grid.size() && c < grid[0].size()) {
            if (visited[r][c] == 0 && grid[r][c] == 0) {
                return true;
            }
        }
        return false;
    }
    int bfs(vector<vector<int>>& grid) {
        int len = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<vector<int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        while (!q.empty()) {
            int x = q.size();
            for (int i = 0; i < x; i++) {
                vector<int> point = q.front(); q.pop();
                int r = point[0]; int c = point[1];
                cout << r << " " << c << endl;
                if (r == grid.size()-1 && c == grid[0].size()-1) {
                    return len;
                }
                if (ch(r+1, c, visited, grid)) {
                    visited[r+1][c] = 1;
                    q.push({r+1, c});
                }
                if (ch(r, c+1, visited, grid)) {
                    visited[r][c+1] = 1;
                    q.push({r, c+1});
                }
                if (ch(r-1, c, visited, grid)) {
                    visited[r-1][c] = 1;
                    q.push({r-1, c});
                }
                if (ch(r, c-1, visited, grid)) {
                    visited[r][c-1] = 1;
                    q.push({r, c-1});
                }
                
            }
            cout << endl;
            len++;
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
