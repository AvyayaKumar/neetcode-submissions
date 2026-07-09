class Point {
public:
    vector<int> coord;
    float dist;

};

class Solution {
public:
    double dis(int x1, int y1) {
        return sqrt(((x1*x1)) + (y1*y1));
    }
    void swap(vector<Point>& points, int index1, int index2) {
        Point temp = points[index1];
        points[index1] = points[index2];
        points[index2] = temp;
    }

    vector<Point> quick_sort(vector<Point>& points) {
        if (points.size() <= 1) {
            return points;
        }
        Point pivot = points[points.size()-1];
        int left = 0;
        for (int i = 0; i < points.size(); i++) {
            if (points[i].dist < pivot.dist) {
                swap(points, i, left); left++;
            }
        }
        swap(points, left, points.size()-1);
        vector<Point> newpoints1; vector<Point> newpoints2;
        for (int i = 0; i < left; i++) {
            newpoints1.push_back(points[i]);
        }
        for (int i = left+1; i < points.size(); i++) {
            newpoints2.push_back(points[i]);
        }
        newpoints1 = quick_sort(newpoints1); newpoints2 = quick_sort(newpoints2);
        newpoints1.push_back(pivot);
        for (int i = 0; i < newpoints2.size(); i++) {
            newpoints1.push_back(newpoints2[i]);
        }
        return newpoints1;

    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<Point> new_points;
        for (int i = 0; i < points.size(); i++) {
            Point temp_point; temp_point.coord = points[i]; temp_point.dist = dis(points[i][0], points[i][1]);
            new_points.push_back(temp_point);
        }
        new_points = quick_sort(new_points);
        for (int i = 0; i < k; i++) {
            ans.push_back(new_points[i].coord); 
            cout << new_points[i].coord[0] << " " << new_points[i].coord[1] << " " << new_points[i].dist << endl;
        }
        return ans;
    }   
};
