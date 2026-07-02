class MinStack {
public:

    vector<int> stak;

    MinStack() {
        
    }
    
    void push(int val) {
        stak.push_back(val);
    }
    
    void pop() {
        stak.pop_back();
    }
    
    int top() {
        return stak[stak.size()-1];     
    }
    
    int getMin() {
        int curr_min = INT_MAX;
        for (int i = 0; i < stak.size(); i++) {
            if (stak[i] < curr_min) {
                curr_min = stak[i];
            }
        }
        return curr_min;
    }
};
