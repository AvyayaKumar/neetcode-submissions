class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len = 1;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<vector<int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                vector<int> v = q.front(); q.pop();
                int r = v[0]; int c = v[1];
                cout << r << " " << c << endl;
                if (r == grid.size()-1 && c == grid[0].size()-1) {
                    return len;
                }

                if (min(r, c) >= 0 && r < grid.size() && c < grid[0].size()) {
                    if (visited[r][c] == 0 && grid[r][c] == 0) {
                        visited[r][c] = 1;
                        q.push({r+1, c});
                        q.push({r-1, c});
                        q.push({r, c+1});
                        q.push({r, c-1});
                        q.push({r+1, c+1});
                        q.push({r+1, c-1});
                        q.push({r-1, c+1});
                        q.push({r-1, c-1});
                    }
                }
            }
            cout << endl;
            len++;
        }
        cout << len << endl;
        return -1;
    }
};