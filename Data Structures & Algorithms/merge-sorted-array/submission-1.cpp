class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy = nums1;
        int pointer1 = 0; int pointer2 = 0; int pointer3 = 0;
        while (pointer1 < m || pointer2 < n) {
            if (pointer1 < m && !(pointer2 < n)) {
                nums1[pointer3] = nums1_copy[pointer1]; pointer1++; pointer3++;
            } else if (!(pointer1 < m) && pointer2 < n) {
                nums1[pointer3] = nums2[pointer2]; pointer3++; pointer2++;
            } else {
                if (nums1_copy[pointer1] <= nums2[pointer2]) {
                    nums1[pointer3] = nums1_copy[pointer1]; pointer3++; pointer1++;
                } else {
                    nums1[pointer3] = nums2[pointer2]; pointer3++; pointer2++;
                }
            }
        } 
    }
};