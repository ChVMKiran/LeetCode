class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */