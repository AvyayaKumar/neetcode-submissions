class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        unordered_set<int> lookup;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (r-l > k) {
                lookup.erase(nums[l]);
                l++;
            }
            if (lookup.find(nums[r]) != lookup.end()) {
                cout << nums[r] << " " << l << " " << r << endl;
                return true;
            }
            lookup.insert(nums[r]);
        }
        return false;
    }
};