class Solution {
public:
    int find_row(vector<vector<int>>& matrix, int target) {
        int top = 0; int bottom = matrix.size()-1;
        while (top <= bottom) {
            int mid = (top+bottom)/2;
            if (target < matrix[mid][0]) {
                bottom = mid-1;
            } else if (target > matrix[mid][matrix[mid].size()-1]) {
                top = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (find_row(matrix, target) == -1) {
            return false;
        }
        vector<int> row = matrix[find_row(matrix, target)];
        int left = 0; int right = row.size()-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (target < row[mid]) {
                right = mid-1;
            } else if (target > row[mid]) {
                left = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }   
};
