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
        if (head->next == nullptr) {
            return head;
        }
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr=curr->next;
        }
        ListNode* nextup = reverseList(head->next);
        ListNode* nexthead = head->next;
        head->next = nullptr;
        while (nextup->next != nullptr) {
            nextup=nextup->next;
        }
        nextup->next = head;
        return curr;
    }
};
