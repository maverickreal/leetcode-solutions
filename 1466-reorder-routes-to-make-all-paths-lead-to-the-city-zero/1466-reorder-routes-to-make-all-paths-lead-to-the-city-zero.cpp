class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))g;
    vi(bool)vis;
    ll func(ll in){
        vis[in]=true;
        ll ans=0;
        for(ll child:g[in]){
            if(!vis[abs(child)]){
                ans+=func(abs(child))+(child>0);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>&v) {
        g.assign(n, {}), vis.assign(n, false);
        for(auto e:v){
            g[e[0]].pb(e[1]);
            g[e[1]].pb(-e[0]);
        }
        return func(0);
    }
};