class Solution {
typedef int ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, time;
    vi(bool)vis;
    vi(ll)disc, low;
    vi(vi(ll))bridges;
    void dfsBridges(const vi(vi(ll))&g, ll nd, ll par) {
        vis[nd] = 1;
        disc[nd] = low[nd] = time++;
        for (ll child : g[nd]) {
            if (child == par){
                continue;
            }
            if (vis[child]) {
                low[nd] = min(low[nd], disc[child]);
            }
            else {
                dfsBridges(g, child, nd);
                low[nd] = min(low[nd], low[child]);
                if (low[child] > disc[nd]){
                    bridges.pb({nd, child});
                }
            }
        }
    }
    void tarjanBridges(const vi(vi(ll))&g) {
        time = 0, n=g.size();
        vis.assign(n, 0), disc.assign(n, -1), low.assign(n, -1);
        for (ll i = 0; i < n; ++i) {
            if (!vis[i]){
                dfsBridges(g, i, -1);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>&e) {
        vi(vi(ll))g(n);
        for(const auto&edge:e){
            g[edge[0]].pb(edge[1]), g[edge[1]].pb(edge[0]);
        }
        tarjanBridges(g);
        return bridges;
    }
};