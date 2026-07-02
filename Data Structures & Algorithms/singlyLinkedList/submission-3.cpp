class LinkedNode {
public:
    int value;
    LinkedNode* next = nullptr;
};

class LinkedList {
public:
    LinkedNode* head;
    LinkedNode* tail;
    LinkedNode* dummy_node;

    LinkedList() {
        head = new LinkedNode; head->value = -1;
        tail = head; dummy_node = head; //just always remember to skip/go past the dummy_node,
        // but it will always have to join the head
        // and tail branches
    }

    //works
    int get(int index) {
        int i = 0;
        LinkedNode* curr = head;
        if (curr == dummy_node) {
            curr=curr->next;
        }
        while (i != index && curr != nullptr) {
            curr = curr->next;
            if (curr == dummy_node) {
                curr = curr->next;
            }
            i++;
        }

        if (curr != nullptr) {
            return curr->value;
        }
        return -1;

    }


    //works
    void insertHead(int val) {
        LinkedNode* newHead = new LinkedNode; newHead->value = val;
        newHead->next = head;
        head = newHead;

    }

    //works
    void insertTail(int val) {
        LinkedNode* newTail = new LinkedNode; newTail->value = val;
        tail->next = newTail;
        tail = newTail;
    }

    bool remove(int index) {
        if (head == dummy_node && tail == dummy_node) {
            return false;
        } //if number of elements in list are 0
        insertHead(-1); LinkedNode* temp_node = head;
        int i = 0;
        LinkedNode* curr = head;
        while (i != index && curr != nullptr) {
            curr = curr->next;
            if (curr == dummy_node) {
                curr = curr->next;
            }
            i++;
        }
        // cout << curr->value << endl;
        if (curr == tail || curr == nullptr) {
            head=head->next;
            return false;
        }
        if (curr == temp_node) {
            if (curr->next == dummy_node) {
                // cout << "true" << endl;
                tail = dummy_node; dummy_node->next = nullptr;
                head=head->next;
                return true;
            } else {
                // cout << "false" << endl;
                head=head->next;
                // cout << head->value << endl;
                head=head->next;
                // cout << head->value << endl;
                return true;
            }
        }
        if (curr->next == tail) {
            // cout << "true" << endl;
            if (curr->next == dummy_node) {
                return false;
            }
            curr->next = nullptr;
            tail = curr;
            head=head->next;
            return true;
        }
        if (curr->next == dummy_node) {
            curr=curr->next;
        }
        curr->next = curr->next->next;
        head=head->next;
        return true;
    }

    //works
    vector<int> getValues() {
        LinkedNode* curr = head;
        vector<int> vals;
        while (curr != nullptr) {
            if (curr == dummy_node) {
                curr=curr->next;
            }
            if (curr != nullptr) {
                vals.push_back(curr->value);
                curr = curr->next;
            }
        }
        return vals;
    }
};
