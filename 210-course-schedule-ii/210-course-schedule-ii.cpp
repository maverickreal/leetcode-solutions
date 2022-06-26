class Solution {
    typedef int ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
    vi(ll)res;
    bool cyclic(const vi(vi(ll))& g, vi(ll)& vis, const ll& cur) {
        vis[cur] = 1;
        for (const ll& j : g[cur]) {
            if (vis[j] == 1)
                return true;
            if (cyclic(g, vis, j))
                return true;
        }
        vis[cur] = 2;
        return false;
    }
    bool func(const ll& cur, const vi(vi(ll))& g, vi(ll)& vis) {
        vis[cur] = true;
        for (const ll& ti : g[cur]) {
            if (vis[ti])continue;
            if (!func(ti, g, vis)) return false;
        }
        res.push_back(cur);
        return true;
    }
public:
    vi(ll) findOrder(ll n, vi(vi(ll))& v) {
        vi(vi(ll))g(n);
        for (const vi(ll)& it : v)
            g[it[0]].push_back(it[1]);
        vi(ll)vis(n);
        for (ll i = 0;i < n;++i) {
            if (!vis[i] && cyclic(g, vis, i))
                return {};
        }
        for (ll i = 0;i < n;++i)
            vis[i] = 0;
        for (ll i = 0;i < n;++i) {
            if (!vis[i]) {
                if (!func(i, g, vis))
                    return {};
            }
        }
        return res;
    }
};