class Solution {
public:
    int hIndex(vector<int>& ct) {
        int sz=ct.size();
        if(!sz)
          return 0;
        sort(ct.begin(),ct.end());
        int res=0;
        for(int i=sz-1;i>-1;--i){
          if(ct[i]<=res)
            return res;
          ++res;
        }
        return res;
    }
};