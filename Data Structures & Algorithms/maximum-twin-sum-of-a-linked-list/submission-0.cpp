/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int maxSum = 0;
        vector<int> nums;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next;
        nums.push_back(slow->val);
        while (fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            // n+=2;
            nums.push_back(slow->val);
        }
        int i = nums.size()-1;
        slow=slow->next;
        while (slow) {
            maxSum = max(maxSum, slow->val + nums[i]);
            // cout << slow->val << " " << nums[i] << endl;
            i--;
            slow=slow->next;
            // cout << maxSum << endl;
        }
        return maxSum;
    }
};