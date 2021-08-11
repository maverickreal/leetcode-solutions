class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int>pq;
        int sz=v.size();
        k=sz-k+1;
        for(int i=0;i<sz;++i){
          pq.push(v[i]);
          if(i>=k)
            pq.pop();
        }
        return pq.top();
      }
};