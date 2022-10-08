class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))dp;
    ll func(const vi(int)&v, ll in, ll rem){
        if(rem<1 || in>=n){
            return 0;
        }
        ll&ans=dp[in][rem];
        if(ans==-1){
            ans=func(v, in+1, rem);
            for(ll i=in+1;i<n;++i){
                if(v[i]>v[in]){
                    ans=max(ans, v[i]-v[in]+func(v, i+1, rem-1));
                }
            }
        }
        return ans;
    }
    int maxProfit(int k, vector<int>&v) {
        n=v.size();
        dp.assign(n, vi(ll)(k+1, -1));
        return func(v, 0, k);
    }
};