class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n, ans;
    vi(vi(ll))g;
    pi dfs(const vi(int)&p, ll nd, ll pre){
        ll ansMps=p[nd], ansActual=0;
        for(const ll&child:g[nd]){
            if(child==pre){
                continue;
            }
            const auto&[mps, actual]=dfs(p, child, nd);
            ans=max({ans, ansMps+actual, ansActual+mps});
            ansMps=max(ansMps, p[nd]+mps);
            ansActual=max(ansActual, p[nd]+actual);
        }
        return {ansMps, ansActual};
    }
    long long maxOutput(int N, vector<vector<int>>& edges, vector<int>& price) {
        n=N, ans=0;
        g.resize(n);
        for(const auto&edge:edges){
            g[edge[0]].pb(edge[1]), g[edge[1]].pb(edge[0]);
        }
        dfs(price, 0, -1);
        return ans;
    }
};