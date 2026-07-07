class Solution {
public:
    vector<int>* vec = new vector<int>(46, -1);
    Solution() {
        (*vec)[0] = 0; (*vec)[1] = 1; (*vec)[2] = 2;
    }
    int climbStairs(int n) {
        if ((*vec)[n] != -1) {
            return (*vec)[n];
        }
        (*vec)[n] = climbStairs(n-1) + climbStairs(n-2);
        return (*vec)[n];
    }
};
