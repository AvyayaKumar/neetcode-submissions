class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0;
        int longest_subarray = 1;
        int comp = 2;
        for (int r = 1; r < arr.size(); r++) {
            if (r == l) continue;
            if (arr[r] > arr[r-1] && comp == 1) {
                l = r-1;
                // r--;
                comp = 2;
            } else if (arr[r] < arr[r-1] && comp == 0) {
                l = r-1;
                // r--;
                comp = 2;
            } 
            else if (arr[r] == arr[r-1]) {
                l = r-1;
                // r--;
                comp = 2;
            }
            if (comp == 2) {
                if (arr[r] > arr[r-1]) comp = 0;
                else if (arr[r] < arr[r-1]) comp = 1;
                else {
                    l = r;
                    continue;
                }
            }
            comp = (comp+1)%2;
            longest_subarray = max(longest_subarray, r-l+1);
        }
        return longest_subarray;

    }
};