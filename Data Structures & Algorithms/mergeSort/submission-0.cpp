// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> merge(vector<Pair> pair1, vector<Pair> pair2) {
        int p1 = 0; int p2 = 0; vector<Pair> ans;
        while (p1 < pair1.size() || p2 < pair2.size()) {
            if (p1 == pair1.size() && p2 < pair2.size()) {
                ans.push_back(pair2[p2]); p2++;
            } else if (p1 < pair1.size() && p2 == pair2.size()) {
                ans.push_back(pair1[p1]); p1++;
            } else {
                if (pair1[p1].key <= pair2[p2].key) {
                    ans.push_back(pair1[p1]); p1++;
                } else if (pair2[p2].key < pair1[p1].key) {
                    ans.push_back(pair2[p2]); p2++;
                }
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].key << " " << ans[i].value << "  ";
        }
        cout << endl;
        return ans;
    }
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.size() <= 1) {
            return pairs;
        }
        int m = pairs.size()/2;
        vector<Pair> pair1, pair2;
        for (int i = 0; i < m; i++) {
            pair1.push_back(pairs[i]);
            // cout << "1 " << pairs[i].value << " ";
        }
        // cout << endl;
        for (int i = m; i < pairs.size(); i++) {
            pair2.push_back(pairs[i]);
            // cout << "2 " << pairs[i].value << " ";
        }
        // cout << endl;
        pair1 = mergeSort(pair1); pair2 = mergeSort(pair2);
        vector<Pair> ans = merge(pair1, pair2);
        return ans;
    }
};
