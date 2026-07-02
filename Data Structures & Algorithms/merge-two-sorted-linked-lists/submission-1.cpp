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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* curr; curr = head;
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val <= list2->val) {
                    curr->val = list1->val;
                    list1 = list1->next;
                        ListNode* next_node = new ListNode();
                        curr->next = next_node;
                        curr = next_node;
                    
                } else if (list2->val < list1->val) {
                    curr->val = list2->val;
                    list2 = list2->next;
                        ListNode* next_node = new ListNode();
                        curr->next = next_node;
                        curr = next_node;

                }
            } else if (list1 && list2 == nullptr) {
                curr->val = list1->val;
                list1 = list1->next;

                if (list1 != nullptr) {
                    ListNode* next_node = new ListNode();
                    curr->next = next_node;
                    curr = next_node;
                }
                
            } else if (list1 == nullptr && list2) {
                curr->val = list2->val;
                list2 = list2->next;
                if (list2 != nullptr) {
                    ListNode* next_node = new ListNode();
                    curr->next = next_node;
                    curr = next_node;
                }


                
                
            }
        }
        return head;
    }
};
