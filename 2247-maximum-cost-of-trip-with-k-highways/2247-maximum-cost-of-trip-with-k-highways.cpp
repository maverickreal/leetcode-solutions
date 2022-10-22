class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(pi))g;
    vi(bool)vis;
    vi(vi(ll))dp;
    ll k;
    ll func(ll nd, ll bm){
        if(vis[nd]){
            return -1;
        }
        if(__builtin_popcount(bm)==k){
            return 0;
        }
        ll&ans=dp[nd][bm];
        if(ans==LLONG_MAX){
            vis[nd]=1, ans=-1;
            for(const pi&p:g[nd]){
                ll rec=func(p.first, bm|(1<<nd));
                if(rec>-1){
                    rec+=p.second;
                }
                ans=max(ans, rec);
            }
            vis[nd]=0;
        }
        return ans;
    }
    int maximumCost(int n, vector<vector<int>>&e, int K) {
        k=K, g.resize(n), vis.resize(n), dp.assign(n, vi(ll)(1<<n, LLONG_MAX));
        for(const auto&edge:e){
            g[edge[0]].pb({edge[1], edge[2]}), g[edge[1]].pb({edge[0], edge[2]});
        }
        ll ans=-1;
        for(ll nd=0;nd<n;++nd){
            ans=max(ans, func(nd, 0));
        }
        return ans;
    }
};