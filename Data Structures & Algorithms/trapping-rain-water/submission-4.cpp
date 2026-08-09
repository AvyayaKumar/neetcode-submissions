class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        leftMax[0] = height[0];
        rightMax[height.size()-1] = height[height.size()-1];
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for (int i = height.size()-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        int totalWater = 0;
        for (int i = 0; i < height.size(); i++) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }
        return totalWater;
    }
};
