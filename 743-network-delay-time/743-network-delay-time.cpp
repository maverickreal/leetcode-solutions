class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)d;
    vi(bool)vis;
    void dijkstraDense(const vi(vi(pi))&g, ll s) { // for max edges; O(v^2)
        ll n = g.size();
        d.assign(n, LLONG_MAX), vis.assign(n, false);
        d[s] = 0;
        for (ll i = 0; i < n; i++) {
            ll v = -1;
            for (ll j = 0; j < n; j++) {
                if (!vis[j] && (v == -1 || d[j] < d[v])){
                    v = j;
                }
            }
            if (v==-1 || d[v] == LLONG_MAX){
                break;
            }
            vis[v] = true;
            for (auto edge : g[v]) {
                ll to = edge.first, w = edge.second;
                if (d[v] + w < d[to]) {
                    d[to] = d[v] + w;
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>&e, int n, int src) {
        vi(vi(pi))g(n);
        for(auto edge:e){
            g[edge[0]-1].pb({edge[1]-1, edge[2]});
        }
        dijkstraDense(g, src-1);
        ll ans=*max_element(begin(d), end(d));
        if(ans==LLONG_MAX){
            ans=-1;
        }
        // for(ll dis:d){
        //     cout<<dis<<' ';
        // }
        // cout<<nl;
        return ans;
    }
};