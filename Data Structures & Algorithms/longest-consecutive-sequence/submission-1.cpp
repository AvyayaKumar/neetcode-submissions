class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(unordered_set<int> nums) {
        for (auto i : nums) {
            par_[i] = i;
            rank_[i] = 1;
        }
    }

    // Find parent of n, with path compression.
    int find(int n) {
        int p = par_[n];
        while (p != par_[p]) {
            par_[p] = par_[par_[p]];
            p = par_[p];
        }
        return p;
    }

    // Union by height / rank.
    // Return false if already connected, true otherwise.
    bool _union(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank_[p1] > rank_[p2]) {
            par_[p2] = p1;
        } else if (rank_[p1] < rank_[p2]) {
            par_[p1] = p2;
        } else {
            par_[p1] = p2;
            rank_[p2] += 1;
        }
        return true;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> new_nums; 
        for (int i : nums) {
            if (!new_nums.contains(i)) new_nums.insert(i);
        }
        // for (auto i : new_nums) cout << i << " ";
        cout << endl;
        UnionFind x(new_nums);
        for (auto i : new_nums) {
            if (new_nums.contains(i+1)) {
                // cout << i << " " << i+1 << endl;
                x._union(i, i+1);
            }
            // if (new_nums.contains(i-1)) x._union(i, i-1);
        }
        cout << endl;
        unordered_map<int, int> stats;
        int ans = 0;
        for (auto i : new_nums) {
            int parent = x.par_[i];
            while (parent != x.par_[parent]) {
                parent = x.par_[parent];
            }
            // cout << i << " " << parent << endl;
            if (stats.contains(parent)) stats[parent]++;
            else stats[parent] = 1;
            ans = max(ans, stats[parent]);
        }
        return ans;
    }
};
