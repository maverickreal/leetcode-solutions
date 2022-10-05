class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, m;
    vi(vi(vi(ll)))dp;
    ll func(const vi(int)&g, const vi(int)&p, ll in, ll rl, ll rp){
        if(rl<0){
            return 0;
        }
        if(in==m){
            return !rp;
        }
        ll&ans=dp[in][rl][rp];
        if(ans==-1){
            ans=(func(g, p, in+1, rl, rp)+func(g, p, in+1, rl-g[in], max(0LL, rp-p[in])))%mod;
        }
        return ans;
    }
    int profitableSchemes(int N, int mn, vector<int>&g, vector<int>&p) {
        n=N, m=g.size();
        dp.assign(m, vi(vi(ll))(n+1, vi(ll)(mn+1, -1)));
        return func(g, p, 0, n, mn);
    }
};