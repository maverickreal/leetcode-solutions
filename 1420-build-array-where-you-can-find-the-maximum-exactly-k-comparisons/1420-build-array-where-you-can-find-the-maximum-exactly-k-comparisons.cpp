class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(vi(ll)))dp;
    ll func(ll in, const ll&m, ll rem, ll mx){
        if(in<0 || rem<0){
            return 0;
        }
        if(in==0){
            return (rem==0);
        }
        ll&ans=dp[in][mx][rem];
        if(ans==-1){
            ans=0;
            for(ll i=1;i<=m;++i){
                ans=(ans+func(in-1, m, rem-(i<mx), min(mx, i)))%mod;
            }
        }
        return ans;
    }
    int numOfArrays(int n, int m, int k) {
        dp.assign(n+1, vi(vi(ll))(m+2, vi(ll)(k+1, -1)));
        return func(n, m, k, m+1);
    }
};