class Solution {
public:
    vector<vector<int>> grid;
    int count = 0;
    void fill(int r, int c, unordered_set<int> visited_r, unordered_set<int> visited_c) {
        if (min(r, c) < 0 || r >= grid.size() || c >= grid[0].size() || (visited_r.find(r) != visited_r.end() && visited_c.find(c) != visited_c.end())) {
            // cout << r << " " << c << endl;
            return;
        } else if (grid[r][c] == 1) {
            // cout << r << " " << c << endl;
            return;
        } else if (r == grid.size() - 1 && c == grid[0].size() - 1) {
            // cout << "found " << r << " " << c << endl;
            count++;
            return;
        }
        
        // cout << "happy " << r << " " << c << endl;
        // cout << "count " << count << endl;
        // visited_r.insert(r); visited_c.insert(c);
        grid[r][c] = 1; 
        fill(r+1, c, visited_r, visited_c);
        fill(r-1, c, visited_r, visited_c);
        fill(r, c+1, visited_r, visited_c);
        fill(r, c-1, visited_r, visited_c);
        // cout << count << endl;
        grid[r][c] = 0;
        // visited_r.erase(r); visited_c.erase(c);

    }

    int countPaths(vector<vector<int>>& inp_grid) {
        grid = inp_grid;
        unordered_set<int> t1; unordered_set<int> t2;
        fill(0, 0, t1, t2);
        return count;
    }
};
