class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int sz=v.size();
    vector<pair<int,int>>l(sz);
    for(int i=0;i<sz;++i)
        l[i]={v[i],i};
    sort(l.begin(),l.end());
    int s=0,e=sz-1;
    while(s<e){
        long sum=l[s].first+l[e].first;
        if(sum==t)
            break;
        if(sum<t)
            ++s;
        else
            --e;
    }
    return vector<int>{l[s].second,l[e].second};
    }
};