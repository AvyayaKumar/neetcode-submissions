class MedianFinder {
public:
    priority_queue<double> small;
    priority_queue<double, vector<double>, greater<double>> large;
    
    MedianFinder() {
        
    }
    
    void addNum(double num) {
        small.push(num);
        if (!large.empty() && small.top() > large.top()) {
            double tmp = small.top();
            small.pop();
            large.push(tmp);
        }

        if (small.size() > large.size()+1) {
            double tmp = small.top();
            small.pop();
            large.push(tmp);
        } else if (large.size() > small.size()+1) {
            double tmp = large.top();
            large.pop();
            small.push(tmp);
        }    
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        } else {
            return (small.top()+large.top())/2.0;
        }
    }
};
