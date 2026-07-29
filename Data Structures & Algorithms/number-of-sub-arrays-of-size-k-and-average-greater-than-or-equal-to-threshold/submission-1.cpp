class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double numofarray = 0;
        double currSum = 0;
        double s = 0;
        int l = 0;
        vector<int> idea;
        for (int r=0; r < arr.size(); r++) {
            if (s+1 > k) {
                currSum -= arr[l];
                s--;
                l++;
                // idea.erase(idea.begin());
            }
            // idea.push_back(arr[r]);
            currSum += arr[r];
            s++;
            if (s == k) {
                
                // cout << "hi" << endl;
                double avg = (currSum / s);
                if (avg >= threshold) {
                    // cout << avg << " " << threshold << " ";
                    // for (int i : idea) {
                    //     cout << i << " ";
                    // }
                    // cout << endl;
                    numofarray++;
                } 
            }
        }
        return numofarray;
    }
};