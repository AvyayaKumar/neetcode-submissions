class Solution {
public:
    bool isValid(string s) {
        vector<char> brackets; 
        for (int i = 0; i < s.length(); i++) {
            char para = s[i];
            if (para == '(' || para == '{' || para == '[') {
                brackets.push_back(para);
            } else {
                if (brackets.size() == 0) {
                    cout << 1 << endl;
                    return false;
                }
                if (para == ')') {
                    if (brackets[brackets.size()-1] != '(') {
                        cout << 2 << endl;
                        return false;
                    } else {
                        brackets.pop_back();
                    }
                }
                if (para == '}') {
                    if (brackets[brackets.size()-1] != '{') {
                        cout << 3 << endl;
                        return false;
                    } else {
                        brackets.pop_back();
                    }
                }
                if (para == ']') {
                    if (brackets[brackets.size()-1] != '[') {
                        cout << 4 << endl;
                        return false;
                    } else {
                        brackets.pop_back();
                    }
                }
            }
        }
        if (brackets.size() > 0) {
            return false;
        }
        return true;
    }
};
