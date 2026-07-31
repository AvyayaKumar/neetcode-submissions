class Solution {
public:
    int binSearch(vector<int>& nums) {
        int n = nums.size();
        int low = 0; int high = nums.size()-1;
        while (true) {
            int mid = (low+high)/2;
            if (nums[(mid+1)%n] < nums[mid]) {
                return nums[(mid+1)%n];
            } else if (nums[mid] < nums[(mid+n-1)%n]) {
                return nums[mid];
            } else {

            }
        }
        return -1;
    }
    int findMin(vector<int> &nums) {
        int mi = 1001;
        for (int i : nums) mi = min(mi, i);
        return mi;
    }
};
