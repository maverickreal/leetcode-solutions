class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll func(ll n, const int&k, ll rem){
        if(!n){
            return !rem;
        }
        if(rem<1){
            return 0;
        }
        ll&ans=dp[n][rem];
        if(ans==-1){
            ans=0;
            for(ll i=1;i<=k;++i){
                ans=(ans+func(n-1, k, rem-i))%mod;
            }
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int tar) {
        dp.assign(n+1, vi(ll)(tar+1, -1));
        return func(n, k, tar);
    }
};