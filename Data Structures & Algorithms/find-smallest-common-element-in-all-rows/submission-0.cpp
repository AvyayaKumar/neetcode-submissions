class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m = (l+r)/2;
        while (l <= r) {
            m = (l+r) / 2;
            if (nums[m] < target) {
                l = m+1;
            } else if (nums[m] > target) {
                r = m-1;
            } else {
                return m;
            }
        }
        return -1;
    }
    bool search(vector<vector<int>>& mat, int target) {
        for (vector<int> v : mat) {
            if (binarySearch(v, target) == -1) return false;
        }
        return true;
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        for (int i : mat[0]) {
            if (search(mat, i)) return i;
        }
        return -1;
    }
};
