class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    MedianFinder() {}

    void addNum(int num) {
        if (small.empty() || num <= small.top())
            small.push(num);
        else
            large.push(num);

        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        else if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size())
            return small.top();

        if (large.size() > small.size())
            return large.top();

        return ((double)small.top() + large.top()) / 2.0;
    }
};