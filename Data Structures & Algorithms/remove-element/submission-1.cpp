class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                count++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                for (int j = i; j < nums.size()-1; j++) {
                    nums[j] = nums[j+1];
                }
                nums[nums.size()-1] = -1;
                if (nums[i] == val) {
                    i--;
                }
            }
            // for (int j = 0; j < nums.size(); j++) {
            //     cout << nums[j] << " ";
            // }
            // cout << endl;
        }
        return count;
    }
};