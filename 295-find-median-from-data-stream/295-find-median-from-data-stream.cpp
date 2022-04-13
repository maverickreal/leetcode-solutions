class MedianFinder {
public:
    multiset<double>mst1, mst2;
    MedianFinder() {
        
    }
    void addNum(int num) {
        int sz1=mst1.size(), sz2=mst2.size();
        if(sz1==sz2){
            mst2.insert(num);
            mst1.insert(*mst2.begin());
            mst2.erase(mst2.begin());
            return;
        }
        mst1.insert(num);
        mst2.insert(*mst1.rbegin());
        mst1.erase(--mst1.end());
    }
    
    double findMedian() {
        int sz1=mst1.size(), sz2=mst2.size();
        if(sz1==sz2)
            return (*mst1.rbegin()+*mst2.begin())/2;
        return *mst1.rbegin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */