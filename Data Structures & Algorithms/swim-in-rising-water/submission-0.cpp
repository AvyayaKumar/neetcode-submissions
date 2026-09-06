class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> min_time(grid.size(), vector<int>(grid[0].size(), -1));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> next_option; //<cost, <r, c>>
        next_option.push({grid[0][0], {0, 0}});
        while (!next_option.empty()) {
            pair<int, pair<int, int>> p = next_option.top();
            next_option.pop();
            int cost = p.first;
            pair<int, int> coords = p.second;
            int r = coords.first;
            int c = coords.second;
            cout << cost << " " << r << " " << c << endl;
            if (min_time[r][c] == -1) {
                min_time[r][c] = cost;
                if (r == grid.size()-1 && c == grid[0].size()-1) {
                    return cost;
                }
                vector<pair<int, int>> neighbors = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for (pair<int, int> dir : neighbors) {
                    int new_r = r+dir.first;
                    int new_c = c+dir.second;
                    if (min(new_r, new_c) >= 0 && new_r < grid.size() && new_c < grid[0].size() && min_time[new_r][new_c] == -1) {
                        next_option.push({max(grid[new_r][new_c], cost), {new_r, new_c}});
                    }
                }
            }
        }
        // cout << endl;
        // for (vector<int> v : min_time) {
        //     for (int i : v) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        // return min_time[grid.size()-1][grid[0].size()-1];
        
    }
};
