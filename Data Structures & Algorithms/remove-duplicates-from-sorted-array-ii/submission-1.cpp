class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int last_num = nums[nums.size()-1];
        int last = nums.size()-1;
        int last_cnt = 0;
        while (nums[last] == last_num && last >= 0) {
            last--;
            last_cnt++;
        }
        int curr_cnt = 0;
        // bool is_first = false; 
        while (r < nums.size()) {
            // if (r == 0) is_first = true;
            // else is_first = false;
            int curr_num = nums[r];
            while (r < nums.size()) {
                if (nums[r] == curr_num) {
                    r++;
                    curr_cnt++;
                } else break;
            }
            for (int i = 0; i < min(curr_cnt, 2); i++) {
                nums[l] = curr_num;
                l++;
            }
            curr_cnt = 0;
        }
        int k = 0;
        while (nums[k] != nums[nums.size()-1]) {
            k++;
        }
        cout << last_cnt << endl;
        k += min(last_cnt, 2);
        // for (int i = 0; i < k; i++) {
        //     cout << nums[i] << " ";
        // }
        return k;
    }
};