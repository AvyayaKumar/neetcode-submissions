class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rotted(grid.size(), vector<int>(grid[0].size(), 0));
        int time = 0;
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                    q.push({i, j});
                }
            }
        }


        while (!q.empty()) {
            int n = q.size();
            bool done = false;
            for (int i = 0; i < n; i++) {
                vector<int> v = q.front(); q.pop();
                int r = v[0]; int c = v[1];
                if (min(r, c) >= 0 && r < grid.size() && c < grid[0].size()) {
                    if (grid[r][c] == 1) {
                        cout << r << " " << c << endl;
                        done = true;
                        grid[r][c] = 2;
                        q.push({r+1, c});
                        q.push({r, c+1});
                        q.push({r-1, c});
                        q.push({r, c-1});
                    }
                }
            }
            if (done) {
                time++;
                cout << time << endl;
                cout << endl;
            }
            
        }


        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        if (time == 0) {
            return time;
        }
        
        return time-1;
    
    }
};
