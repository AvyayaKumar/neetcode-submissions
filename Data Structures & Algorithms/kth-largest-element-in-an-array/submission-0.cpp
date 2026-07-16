class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i:nums) pq.push(i);
        int ans;
        for(int i=0;i<k;i++) {
            ans=pq.top();pq.pop();
        }
        return ans;
    }
};
