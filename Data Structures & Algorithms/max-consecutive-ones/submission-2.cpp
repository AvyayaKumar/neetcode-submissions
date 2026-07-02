class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0;
        bool consecutive = false;
        int count = 0;
        int startindex;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1 && consecutive == false) {
                consecutive = true;
                startindex = i;
            } else if (nums[i] == 0 && consecutive == true) {
                consecutive = false;
                count = i-startindex;
                if (count > maxcount) {
                    maxcount = count;
                }
                // cout << startindex << " " << i << endl;
            } else if (nums[i] == 1 && consecutive == true) {
                count = i-startindex+1;
                if (count > maxcount) {
                    maxcount = count;
                }
                // cout << startindex << " :( " << i << endl;
            }
        }
        if (nums.size() == 1) {
            if (nums[0] == 1) {
                return 1;
            }
        }
        return maxcount;
    }
};