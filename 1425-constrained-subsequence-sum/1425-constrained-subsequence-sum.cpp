class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int constrainedSubsetSum(vector<int>&v, int k) {
        ll mx=*max_element(begin(v), end(v));
        if(mx<1){
            return mx;
        }
        ll n=v.size();
        vi(ll)dp(n);
        map<ll,ll>mp={{0, 1}};
        for(ll i=0;i<n;++i){
            if(i>k){
                --mp[dp[i-k-1]];
                if(!mp[dp[i-k-1]]){
                    mp.erase(dp[i-k-1]);
                }
            }
            dp[i]=v[i]+mp.rbegin()->first;
            ++mp[dp[i]];
        }
        return *max_element(begin(dp), end(dp));
    }
};