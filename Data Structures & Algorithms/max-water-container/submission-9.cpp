class Solution {
public:
    int maxArea(vector<int>& heights) {
        // vector<vector<int>> memoization(heights.size(), vector<int>(heights.size(), -1));
        int max_water = 0;
        // vector<int> copy_heights = heights; sort(copy_heights.begin(), copy_heights.end(), greater<int>());
        // int second_max_height = copy_heights[1];
        // cout << second_max_height << endl;
        int l = 0; int r = heights.size()-1;
        while (l < r) {
            max_water = max(max_water, (r-l)*min(heights[r], heights[l]));
            if (heights[r] > heights[l]) l++;
            else r--;
        }
        return max_water;
    }
};
