class Solution {
public:
  class cmp{
  public:
    bool operator()(const pair<int,int>&p,const pair<int,int>&q){
      return p.first<q.first;
    }
  };
    int canCompleteCircuit(vector<int>& gas, vector<int>& costs) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        int sz=gas.size();
        for(int i=0;i<sz;++i)
          pq.push({gas[i]-costs[i],i});
        while(!pq.empty() and pq.top().first>-1){
          int i,in=pq.top().second,t=0,pre=0;
          //cout<<in<<' ';
          pq.pop();
          for(i=0;i<=sz;++i){
            int j=(i+in)%sz;
            //cout<<j<<' '<<t<<' '<<pre<<'\n';
            t-=pre;
            pre=costs[j];
            if(t<0)
              break;
            t+=gas[j];
          }
          if(i==sz+1 and t>-1)
            return in;
          //cout<<"failed for  "<<in<<'\n';
        }
        return -1;
    }
};