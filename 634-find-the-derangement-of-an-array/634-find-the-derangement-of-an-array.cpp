class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)dp;
    ll func(ll n) {
        if(n<3){
            return n-1;
        }
        if(dp[n]==-1){
            dp[n]=((n-1)*((func(n-1)+func(n-2))%mod))%mod;
        }
        return dp[n];
    }
    ll findDerangement(ll n){
        dp.assign(n+1, -1);
        return func(n);
    }
};