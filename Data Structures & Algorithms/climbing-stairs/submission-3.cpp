class Solution {
public:
    unordered_map<int, int> m; 
    int climbStairs(int n) {
        if (n <= 2) return n;
        if (m.find(n) != m.end()) return m[n];
        m[n] = climbStairs(n-1) + climbStairs(n-2);
        return m[n];
    }
};
