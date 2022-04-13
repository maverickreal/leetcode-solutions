class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<double, vector<double>, greater<double>>pq2;
    MedianFinder() {
        
    }
    void addNum(int num) {
        int sz1=pq1.size(), sz2=pq2.size();
        if(sz1==sz2){
            pq2.push(num);
            pq1.push(pq2.top());
            pq2.pop();
            return;
        }
        pq1.push(num);
        pq2.push(pq1.top());
        pq1.pop();
    }
    
    double findMedian() {
        int sz1=pq1.size(), sz2=pq2.size();
        if(sz1==sz2)
            return (pq1.top()+pq2.top())/2;
        return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */