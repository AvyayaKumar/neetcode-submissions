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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> states;
        for (int i = 0; i < pairs.size(); i++) {
            int j = i-1;
            while (j >= 0 && pairs[j+1].key < pairs[j].key) {
                // cout << pairs[j+1].key << " " << pairs[j].key << endl;
                //swap
                Pair temp_pair = pairs[j+1];
                pairs[j+1] = pairs[j]; pairs[j] = temp_pair;
                j--;
                //add to states
            }
            vector<Pair> temp_state;
            for (int k = 0; k < pairs.size(); k++) {
                temp_state.push_back(pairs[k]);
            }
            states.push_back(temp_state);
        }
        return states;
    }
};
