class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)d, vis;
    ll n;
    vi(vi(pi))g;
    void dijkstraSparse() {
        const ll s=n-1;
        d.assign(n, LLONG_MAX);
        d[s] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push({0, s});
        while (!q.empty()) {
            ll v = q.top().second, dist = q.top().first;
            q.pop();
            if (dist != d[v]){
                continue;
            }
            for (auto edge : g[v]) {
                ll to = edge.first, w = edge.second;
                if (d[v] + w < d[to]) {
                    d[to] = d[v] + w;
                    q.push({d[to], to});
                }
            }
        }
    }
    ll dfs(ll nd){
        if(nd==n-1){
            return 1;
        }
        ll&ans=vis[nd];
        if(ans==-1){
            ans=0;
            for(pi child:g[nd]){
                if(d[child.first]<d[nd]){
                    ans=(ans+dfs(child.first))%mod;
                }
            }
        }
        return ans;
    }
    int countRestrictedPaths(int N, vector<vector<int>>&e) {
        n=N;
        vis.assign(n, -1), g.resize(n);
        for(auto edge:e){
            g[edge[0]-1].pb({edge[1]-1, edge[2]});
            g[edge[1]-1].pb({edge[0]-1, edge[2]});
        }
        dijkstraSparse();
        return dfs(0);
    }
};