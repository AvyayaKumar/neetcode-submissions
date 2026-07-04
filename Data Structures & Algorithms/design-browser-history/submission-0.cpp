class tab {
public:
    string value; tab* next = nullptr; tab* prev = nullptr;
};

class BrowserHistory {
public:
    tab* hpage;
    tab* head;
    tab* tail;
    tab* curr;
    
    BrowserHistory(string homepage) {
        hpage = new tab; hpage->value = homepage;    
        head = hpage; tail = head; curr = head;
    }
    
    void visit(string url) {
        tab* npage = new tab; npage->value = url; 
        curr->next = npage; npage->prev = curr;
        curr=curr->next;
        printall();
    }
    
    string back(int steps) {
        cout << "1 " << curr->value << endl;
        int i = 0; 
        while (i != steps && curr->prev != nullptr) {
            i++; curr=curr->prev;
        }
        return curr->value;

    }
    
    string forward(int steps) {
        int i = 0;
        while (i != steps && curr->next != nullptr) {
            i++; curr=curr->next;
        }
        return curr->value;
    }
    void printall() {
        tab* temp = hpage;
        while (temp != nullptr) {
            cout << temp->value << " "; temp=temp->next;
        }
        cout << endl;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */