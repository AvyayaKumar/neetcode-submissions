class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int greatest_right = 0;
            for (int j = i+1; j < arr.size(); j++) {
                if (arr[j] > greatest_right) {
                    greatest_right = arr[j];
                }
            }
            arr[i] = greatest_right;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};