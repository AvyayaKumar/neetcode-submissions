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
    int find_min(vector<ListNode*> vec) {
        int least = INT_MAX;
        ListNode* least_pointer;
        int index;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != nullptr) {
                if (vec[i]->val < least) {
                    least = vec[i]->val;
                    least_pointer = vec[i];
                    index = i;
                }
            }
        }
        return index;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode* curr = new ListNode; ListNode* head = curr;
        while (true) {
            int index = find_min(lists);
            cout << lists[index]->val << " ";
            curr->val = lists[index]->val;
            
            lists[index] = lists[index]-> next;
            bool stop = true;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr) {
                    stop = false;
                }
            }
            if (stop) {
                break;
            }
            ListNode* temp = new ListNode; curr->next = temp; curr = temp;
        }
        return head;
    }
};
