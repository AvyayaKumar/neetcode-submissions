class Solution {
public:
    int eating(vector<int>& piles, int k) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (ceil((double) piles[i]/k));
            // cout << hours << " ";
        }
        // cout << endl;
        return hours;
    }

    int check(int hours, int limit) {
        if (hours < limit) {
            return -1;
        } else if (hours > limit) {
            return 1;
        }  else {
            return 0;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; int high = 0;
        for (int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }
        int curr_best_k; 
        while (low <= high) {
            int mid = (low+high)/2;
            int checker = check(eating(piles, mid), h);
            cout << mid << " " << checker << " " << endl;
            if (checker == 1) {
                low=mid+1;
            } else if (checker == -1) {
                high=mid-1;
                curr_best_k = mid;
            } else {
                high=mid-1;
                curr_best_k = mid;
            }
        }
        return curr_best_k;
    }
};
