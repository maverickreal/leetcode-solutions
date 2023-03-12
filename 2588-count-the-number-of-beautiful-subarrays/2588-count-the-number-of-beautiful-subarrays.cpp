class Solution {
public:
    typedef long long ll;
    ll beautifulSubarrays(const vector<int>&v) {
        ll sz=v.size(), ans=0;
        unordered_map<ll,ll>ump={{0, 1}};
        for(ll i=0, xo=0;i<sz;++i){
            xo^=v[i];
            ans+=ump[xo]++;
        }
        return ans;
    }
};