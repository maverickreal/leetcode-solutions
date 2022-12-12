class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
public:
    int numberOfArithmeticSlices(vector<int>&v) {
        ll n=v.size();
        if(n<3){
            return 0;
        }
        vector<unordered_map<ll,pi>>ump(n);
        ump[1][ll(v[1])-v[0]].second=1;
        ll ans=0;
        for(ll i=2;i<n;++i){
            for(ll j=i-1;j>-1;--j){
                ll dif=ll(v[i])-v[j];
                ll pre=ump[j][dif].first;
                ump[i][dif].first+=pre, ans+=pre;
                pre=ump[j][dif].second;
                ump[i][dif].first+=pre, ans+=pre;
                ++ump[i][dif].second;
            }
        }
        return ans;
    }
};