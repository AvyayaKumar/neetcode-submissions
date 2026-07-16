class Solution {
public:
    static double dis(int x1, int y1) {
        return sqrt(((x1*x1)) + (y1*y1));
    }
    static bool comp(vector<int> point1, vector<int> point2) {
        return (dis(point1[0], point1[1]) > dis(point2[0], point2[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> pq (comp);
        for (vector<int> i : points) pq.push(i);
        vector<vector<int>> ans;
        int j = 0;
        while (j < k) {
            vector<int> i = pq.top(); pq.pop(); cout << i[0] << " " << i[1] << endl;
            ans.push_back(i);
            j++;
        }
        
        return ans;
    }
};
