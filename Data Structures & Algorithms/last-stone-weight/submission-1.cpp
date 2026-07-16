class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for (int i : stones) p.push(i);
        while (p.size() > 1) {
            int s1 = p.top(); p.pop(); int s2 = p.top(); p.pop();
            if (s1 != s2) p.push(max(s1, s2) - min(s1, s2));
        }
        if (p.size() == 0) return 0;
        return p.top();
    }
};
