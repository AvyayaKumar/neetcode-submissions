class NumArray {
public:
    vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        int total = 0;
        for (int i : nums) {
            total += i;
            prefix_sum.push_back(total);
        }
        // for (int i : prefix_sum) {
        //     cout << i << " ";
        // }
    }
    
    int sumRange(int left, int right) {
        // return 0;
        return (left <= 0) ? prefix_sum[right] : prefix_sum[right] - prefix_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */