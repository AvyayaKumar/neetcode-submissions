class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> courses;
        unordered_map<int, vector<int>> req;
        vector<int> isdone(numCourses, 1);
        for (int i = 0; i < prerequisites.size(); i++) {
            int prereq = prerequisites[i][1]; int course = prerequisites[i][0];

            if (courses.find(prereq) == courses.end()) courses[prereq] = {course};
            else courses[prereq].push_back(course);

            if (req.find(course) == req.end()) req[course] = {prereq};
            else req[course].push_back(prereq);
            if (req.find(prereq) == req.end()) req[prereq] = {};

            isdone[prereq] = 0; isdone[course] = 0;
        }
        queue<int> unlocked_courses;

        for (auto it = req.begin(); it != req.end(); it++) {
            if (it->second.size() == 0) {
                unlocked_courses.push(it->first);
                cout << it->first << " ";
                isdone[it->first] = 1;
            }
        }
        cout << endl;

        while (!unlocked_courses.empty()) {
            int n = unlocked_courses.size();
            for (int c = 0; c < n; c++) {
                int course = unlocked_courses.front(); unlocked_courses.pop();
                // cout << course << "  ";
                for (int i = 0; i < courses[course].size(); i++) {
                    bool can_advance = true;
                    for (int j = 0; j < req[courses[course][i]].size(); j++) {
                        if (isdone[req[courses[course][i]][j]] == 0) {
                            can_advance = false; break;
                        }
                    }
                    if (can_advance) {
                        unlocked_courses.push(courses[course][i]);
                        cout << courses[course][i] << " ";
                        isdone[courses[course][i]] = 1;
                    }
                }
                // cout << endl;
                // cout << endl;
            }
        }
        cout << endl;

        for (int i : isdone) {
            if (i == 0) return false;
        }


        return true;
    }
};
