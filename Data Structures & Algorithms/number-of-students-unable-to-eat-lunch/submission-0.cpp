class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        stack<int> swich;
        reverse(sandwiches.begin(), sandwiches.end());
        for (int i : sandwiches) {
            swich.push(i);
        }
        queue<int> stud;
        for (int i : students) {
            stud.push(i);
        }
        while (count <= students.size() && stud.size() > 0) {
            int curr_sandwich = swich.top();
            int curr_student = stud.front();
            if (curr_sandwich == curr_student) {
                stud.pop();
                swich.pop();
                count = 0;
            } else {
                stud.pop();
                stud.push(curr_student);
                count++;
            }
        }
        return stud.size();
    }
};