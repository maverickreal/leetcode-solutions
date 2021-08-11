class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>ump;
        for(int i:nums)
          ++ump[i];
        vector<int>res;
        for(auto it=ump.begin();it!=ump.end();++it){
          pq.push({it->second,it->first});
          if(pq.size()>k)
            pq.pop();
        }
        while(!pq.empty()){
          res.push_back(pq.top().second);
          pq.pop();
        }
        return res;
    }
};