class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> duplicate_nums;
        for (int i : nums) {
            if (duplicate_nums.find(i) == duplicate_nums.end()) duplicate_nums.insert(i);
        }
        vector<int> nums_copy;
        for (auto i : duplicate_nums) nums_copy.push_back(i);
        nums = nums_copy;
        return nums.size();
    }
};