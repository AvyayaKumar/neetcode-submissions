class KthLargest {
public:
    int k; vector<int> nums;
    KthLargest(int k_inp, vector<int>& nums_inp) {
        k = k_inp; nums = nums_inp; sort(nums.begin(), nums.end());
    }
    
    int add(int val) {
        nums.push_back(val); sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
        
    }
};
