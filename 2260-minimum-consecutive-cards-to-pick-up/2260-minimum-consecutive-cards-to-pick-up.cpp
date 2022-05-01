class Solution {
public:
    int minimumCardPickup(vector<int>&v) {
        int sz=v.size();
        unordered_map<int, vector<int>>ump;
        for(int i=0;i<sz;++i)
            ump[v[i]].push_back(i);
        int res=INT_MAX;
        for(const auto&it:ump){
            for(int i=0;i<it.second.size()-1;++i)
                res=min(res, it.second[i+1]-it.second[i]+1);
        }
        return (res==INT_MAX?-1:res);
    }
};