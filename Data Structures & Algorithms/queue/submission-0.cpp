class Node {
public:
    int value = -10; Node* prev=nullptr; Node* next=nullptr;
};

class Deque {
public:
    Node* head; Node* tail; Node* dummy_node;
    Deque() {
        head = nullptr; tail = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr && tail == nullptr);

    }

    void append(int val) {
        if (tail == nullptr) {
            tail = new Node; tail->value = val; head = tail;
        } else {
            Node* new_node = new Node; new_node->value = val;
            new_node->prev = tail; tail->next = new_node; tail = new_node;
        }
    }

    void appendleft(int val) {
        if (head == nullptr) {
            head = new Node; head->value = val; tail = head;
        } else {
            Node* new_node = new Node; new_node->value = val;
            new_node->next = head; head->prev = new_node; head = new_node;
        }
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        if (head == tail) {
            int ans = head->value; 
            head = nullptr; tail = nullptr;
            return ans;
        }
        int ans = tail->value;
        Node* temp_tail = tail;
        tail=tail->prev; tail->next = nullptr; temp_tail->prev = nullptr;
        return ans;
    }

    int popleft() {
        if (isEmpty()) {
            return -1;
        }
        if (head == tail) {
            int ans = head->value; 
            head = nullptr; tail = nullptr;
            return ans;
        }
        int ans = head->value;
        Node* temp_head = head;
        head=head->next; temp_head->next = nullptr; head->prev = nullptr;
        return ans;
    }
};
