class MyStack {
public:

    vector<int> stak;

    MyStack() {
        
    }
    
    void push(int x) {
        stak.push_back(x);        
    }
    
    int pop() {
        int ans = stak[stak.size()-1];
        stak.pop_back();
        return ans;
    }
    
    int top() {
        return stak[stak.size()-1];
    }
    
    bool empty() {
        return (stak.size()==0); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */