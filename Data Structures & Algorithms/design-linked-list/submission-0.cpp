class Node {
public:
    int val = -1;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class MyLinkedList {
public:

    Node* head; Node* tail; Node* dummy_node;

    MyLinkedList() {
        head = new Node; tail = head; dummy_node = tail; // dummy node
    }

    int get(int index) {
        Node* curr = head;
        int i = 0;
        while (i != index && curr) {
            if (curr) {
                // cout << "hello ";
                curr=curr->next; i++;
                if (curr == dummy_node) {
                    curr=curr->next;
                }
            }
        }
        // cout << curr->val << endl;
        if (curr) {
            return curr->val;
        }
        return -1;
    }

    void addAtHead(int value) {
        Node* new_head = new Node; new_head->val = value;
        new_head->next = head; head->prev = new_head;
        head = new_head;
    }

    void addAtTail(int value) {
        Node* new_tail = new Node; new_tail->val = value;
        new_tail->prev = tail; tail->next = new_tail;
        tail = new_tail;
    }

    void addAtIndex(int index, int value) {
        if (index == 0) {
            addAtHead(value);
        } else {
            addAtTail(-1); //dummy value dummy value
            int i = 0; Node* curr = head;
            while (i != index && curr) {
                i++; curr=curr->next;
                if (curr == dummy_node) {
                    curr=curr->next;
                }
            }
            if (curr == dummy_node) {
                curr=curr->next;
            }
            if (curr) {
                Node* new_node = new Node; new_node->val = value;
                Node* curr_prev = curr->prev;
                new_node->next=curr; curr->prev=new_node;
                curr_prev->next=new_node; new_node->prev=curr_prev;
            }
            Node* fake_tail = tail;
            tail=tail->prev; fake_tail->prev=nullptr; tail->next = nullptr;
        }

    }

    void deleteAtIndex(int index) {
        int i = 0; Node* curr = head;
        while (i != index && curr) {
            i++; curr=curr->next;
            if (curr == dummy_node) {
                curr=curr->next;
            }
        }
        if (curr == dummy_node) {
            curr=curr->next;
        }
        if (curr) {
            if (curr == head) {
                head=head->next;
                head->prev = nullptr;
            } else if (curr == tail) {

                tail=tail->prev;
                tail->next = nullptr;
            } else {
                curr=curr->prev;
                curr->next = curr->next->next;
                curr=curr->next;
                curr->prev = curr->prev->prev;
            }
        }

    }

    void printall() {
        Node* curr = head;
        while (curr) {
            if (curr == dummy_node) {
                curr=curr->next;
            }
            if (curr) {
                cout << curr->val << " ";
                curr = curr->next;
            }
        }
        cout << endl;
    }
    void printallrev() {
        Node* curr = tail;
        while (curr) {
            if (curr == dummy_node) {
                curr=curr->prev;
            }
            if (curr) {
                cout << curr->val << " ";
                curr = curr->prev;
            }
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */