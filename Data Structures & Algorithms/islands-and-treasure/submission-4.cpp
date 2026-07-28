class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = 2147483647;
        queue<pair<int, int>> treasure_chests;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    treasure_chests.push({i, j});
                    grid[i][j] = inf;
                }
            }
        }
        int len = 0;
        while (!treasure_chests.empty()) {
            int n = treasure_chests.size();
            for (int i = 0; i < n; i++) {
                pair<int, int> point = treasure_chests.front(); treasure_chests.pop();
                if (point.first >= grid.size() || point.second >= grid[0].size() || min(point.first, point.second) < 0) continue;
                if (grid[point.first][point.second] != inf) continue;
                grid[point.first][point.second] = len;
                treasure_chests.push({point.first+1, point.second});
                treasure_chests.push({point.first-1, point.second});
                treasure_chests.push({point.first, point.second+1});
                treasure_chests.push({point.first, point.second-1});   
            }
            len++;
        }
    }
};
