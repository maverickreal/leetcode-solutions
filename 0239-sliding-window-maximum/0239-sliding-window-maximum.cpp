class Solution {
public:
    class cmp{
        public:
        bool operator()(const tuple<int, int>&a, const tuple<int, int>&b){
            return get<1>(a)<get<1>(b);
        }
    };
    vector<int> maxSlidingWindow(vector<int>&v, int k) {
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, cmp>pq;
        vector<int>ans;
        for(int i=0;i<k-1;++i){
            pq.push(make_tuple(i, v[i]));
        }
        for(int i=k-1;i<v.size();++i){
            pq.push(tuple<int, int>(i, v[i]));
            while(get<0>(pq.top())<i-k+1){
                pq.pop();
            }
            ans.push_back(get<1>(pq.top()));
        }
        return ans;
    }
};