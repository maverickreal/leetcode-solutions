class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(pi))g;
    vi(ll)vis;
    ll ans=0;
    void func(ll nd, ll par, ll sum, ll rem, const vi(int)&val){
        if(rem<0){
            return;
        }
        if(!vis[nd]){
            sum+=val[nd];
        }
        ++vis[nd];
        if(nd==0){
            ans=max(ans, sum);
        }
        for(const pi&child:g[nd]){
            func(child.first, nd, sum, rem-child.second, val);
        }
        --vis[nd];
    }
    int maximalPathQuality(vector<int>&val, vector<vector<int>>&e, int t) {
        g.resize(val.size());
        for(const auto&edge:e){
            g[edge[0]].pb({edge[1], edge[2]}), g[edge[1]].pb({edge[0], edge[2]});
        }
        vis.assign(val.size(), 0);
        func(0, -1, 0, t, val);
        return ans;
    }
};