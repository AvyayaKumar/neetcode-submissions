class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (freq[index] <= 0 && index < freq.size()) {
                index++;
            }
            nums[i] = index; freq[index]--;
        }
    }
};