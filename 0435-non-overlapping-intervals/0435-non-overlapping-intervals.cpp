class Solution {
public:
class cmp{
public:
    bool operator()(const vector<int>&a, const vector<int>&b){
        return (a[0]==b[0]?a[1]<b[1]:a[0]<b[0]);
    }
};

    int eraseOverlapIntervals(vector<vector<int>>&v) {
        int n=v.size();
        sort(begin(v), end(v), cmp());
        int ans=0;
        for(int i=0, pre=-1; i<n; ++i){
            if(pre!=-1 && v[i][0]<v[pre][1]){
                ++ans;
                if(v[i][1]<v[pre][1]){
                    pre=i;
                }
            }
            else{
                pre=i;
            }
        }
        return ans;
    }
};
