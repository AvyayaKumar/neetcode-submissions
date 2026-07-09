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
    void swap(vector<Pair>& pairs, int index1, int index2) {
        Pair temp = pairs[index1];
        pairs[index1] = pairs[index2];
        pairs[index2] = temp;
    }
    vector<Pair> quickSort(vector<Pair>& pairs) {
        vector<Pair> ans;
        if (pairs.size() <= 1) {
            return pairs;
        }
        Pair pivot = pairs[pairs.size()-1];
        int left = 0;
        for (int i = 0; i < pairs.size()-1; i++) {
            if (pairs[i].key < pivot.key) {
                swap(pairs, i, left);
                left++;
            }
        }
        swap(pairs, pairs.size()-1, left); 
        vector<Pair> newpair1; vector<Pair> newpair2;
        for (int i = 0; i < left; i++) {
            newpair1.push_back(pairs[i]);
        }
        for (int i = left+1; i < pairs.size(); i++) {
            newpair2.push_back(pairs[i]);
        }
        vector<Pair> sort_newpair1 = quickSort(newpair1);
        vector<Pair> sort_newpair2 = quickSort(newpair2);
        sort_newpair1.push_back(pivot);
        for (int i = 0; i < sort_newpair2.size(); i++) {
            sort_newpair1.push_back(sort_newpair2[i]);
        }
        return sort_newpair1;
    }
};
