class Solution {
public:
    int findMinimumTime(vector<vector<int>>&v) {
        int sz=v.size();
        sort(begin(v), end(v), [](const vector<int>&a, const vector<int>&b){return a[1]<b[1];});
        bitset<2001>time(0);
        for(const auto&task:v){
            int start=task[0], end=task[1], req=task[2];
            for(int i=start;i<=end && req>0;++i){
                req-=time[i];
            }
            for(int i=end;req>0;--i){
                if(!time[i]){
                    time[i]=1, --req;
                }
            }
        }
        return time.count();
    }
};