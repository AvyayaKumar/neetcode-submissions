class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second > b.second;
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> possible;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> impossible;
        for (int i = 0; i < profits.size(); i++) {
            pair<int, int> p = {profits[i], capital[i]};
            if (capital[i] <= w) {
                possible.push(p);
            } else {
                impossible.push(p);
            }
        }
        // while (!possible.empty()) {
        //     cout << possible.top().first << " " << possible.top().second << endl;
        //     possible.pop();
        // }

        // return 0;
        if (possible.empty()) return w;
        for (int i = 0; i < k; i++) {
            w += possible.top().first;
            cout << possible.top().first << " " << possible.top().second << endl;
            possible.pop();
            while (!impossible.empty() && impossible.top().second <= w) {
                possible.push(impossible.top());
                impossible.pop();
            }
        }
        return w;
    }
};