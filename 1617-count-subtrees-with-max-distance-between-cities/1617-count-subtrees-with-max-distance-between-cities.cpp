class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(int)ans;
    bool exists(const vi(vi(ll))& g, ll root, const ll& bm) { // whether or not there exists such a subgraph
        list<ll>q = { root };
        ll vis = 0; // bitmask
        while (!q.empty()) {
            ll nd = q.front();
            q.pop_front();
            vis |= 1 << nd;
            for (ll child : g[nd]) {
                if ((bm & (1 << child)) && !(vis & (1 << child))) {
                    q.pb(child);
                }
            }
        }
        return (bm == vis);
    }
    pi dfs(const vi(vi(ll))& g, ll root, ll par, const  ll& bm /* BitMask */) { //  return {max path len from root, max arc len anywhere in subgraph from root}
        pi ret = { 1, 0 };
        ll mcp1 = 0, mcp2 = 0; // MaxChildPath 1 & 2 lens for forming arc pivoted at root
        for (ll child : g[root]) {
            if (child != par && (bm & (1 << child))) {
                pi rec = dfs(g, child, root, bm);
                ret.first = max(ret.first, rec.first + 1);
                ret.second = max(ret.second, rec.second);
                if (rec.first >= mcp1) {
                    mcp2 = mcp1, mcp1 = rec.first;
                }
                else if (rec.first > mcp2) {
                    mcp2 = rec.first;
                }
            }
        }
        ret.second = max(ret.second, mcp1 + mcp2);
        return ret;
    }
    void func(const vi(vi(ll))& g, const ll& bm) {
        ll root = -1, n = g.size();
        for (ll i = 0;i < n;++i) {
            if (bm & (1 << i)) {
                root = i;
                break;
            }
        }
        if (root > -1 && root < n && exists(g, root, bm)) {
            ll mxPathLen = dfs(g, root, -1, bm).second;
            //cout << root << ' ' << bm << ' ' << mxPathLen << nl;
            if (mxPathLen > 0) {
                ++ans[mxPathLen - 1];
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vi(vi(ll))g(n);
        for (auto it : edges) {
            g[it[0] - 1].pb(it[1] - 1);
            g[it[1] - 1].pb(it[0] - 1);
        }
        ans.resize(n - 1, 0);
        for (ll bm = 0;bm < (1 << n);++bm) {
            func(g, bm);
        }
        return ans;
    }
};