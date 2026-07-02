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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        vector<int> linkedlist;
        vector<int> reverselinkedlist;
        ListNode* curr = head;
        while (curr != nullptr) {
            linkedlist.push_back(curr->val); curr=curr->next;
            reverselinkedlist.push_back(0);
        }
        for (int i = 0; i < linkedlist.size(); i++) {
            reverselinkedlist[i] = linkedlist[linkedlist.size()-1-i];
        }
        ListNode* curr2 = head;
        int i = 0;
        while (curr2 != nullptr) {
            curr2->val = reverselinkedlist[i]; i++; curr2=curr2->next; 
        }
        return head;
    }
};
