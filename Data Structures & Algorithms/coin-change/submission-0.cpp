class Solution {
public:
    vector<int> memo;
    int great;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater());
        this->great = amount+1;
        memo.resize(amount+1, -1);
        memo[0] = 0;
        // return 0;
        int ans = dp(coins, amount);
        if (ans > amount) return -1;
        return ans;
    }
    int dp(vector<int>& coins, int amount) {
        // if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];
        int i = 0;
        while (i < coins.size() && amount - coins[i] < 0) {
            i++;
        }
        int best_path = great;
        while (i < coins.size()) {
            int path = 1 + dp(coins, amount-coins[i]);
            best_path = min(path, best_path);
            i++;
        }
        memo[amount] = best_path;
        // if (memo[amount] == INT_MAX) return -1;
        return memo[amount];
    }
};
