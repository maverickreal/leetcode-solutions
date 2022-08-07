class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll szv, szr;
    vi(vi(ll))g;
    vi(bool)r;
    ll func(ll in, ll par) {
        if (in >= szv || r[in]) {
            return 0;
        }
        ll res = 1;
        for (ll ch : g[in]) {
            if (ch != par) {
                res += func(ch, in);
            }
        }
        return res;
    }
    int reachableNodes(int n, vector<vector<int>>& v, vector<int>& res) {
        szv = n, szr = res.size();
        g.resize(szv);
        for (vi(int) ed : v) {
            g[ed[0]].pb(ed[1]);
            g[ed[1]].pb(ed[0]);
        }
        r.resize(szv);
        for (ll it : res) {
            r[it] = true;
        }
        return func(0, -1);
    }
};