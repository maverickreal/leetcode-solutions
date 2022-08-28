class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    void topo(const vi(unordered_set<ll>)& g, vi(ll)& res) {
        ll k = g.size(), vis = 0;
        vi(ll)indeg(k, 0);
        list<ll>l;
        for (ll i = 0;i < k;++i) {
            for (ll child : g[i]) {
                ++indeg[child];
            }
        }
        for (ll i = 0;i < k;++i) {
            if (indeg[i] == 0) {
                l.pb(i);
            }
        }
        while (!l.empty()) {
            ll it = l.front();
            l.pop_front();
            res.pb(it);
            for (ll child : g[it]) {
                --indeg[child];
                if (indeg[child] == 0) {
                    l.pb(child);
                }
            }
            ++vis;
        }
        if (vis != k) {
            res.clear();
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vi(unordered_set<ll>)gr(k), gc(k);
        for (auto it : rc) {
            gr[it[0] - 1].insert(it[1] - 1);
        }
        for (auto it : cc) {
            gc[it[0] - 1].insert(it[1] - 1);
        }
        vi(ll)ro, co;
        topo(gr, ro);
        if (ro.size() < k) {
            return {};
        }
        topo(gc, co);
        if (co.size() < k) {
            return {};
        }
        vi(vi(int))ans(k, vi(int)(k, 0));
        vi(ll)ump(k, -1);
        for (ll i = 0;i < k;++i) {
            ump[co[i]] = i;
        }
        for (ll i = 0;i < k;++i) {
            ans[i][ump[ro[i]]] = ro[i] + 1;
        }
        return ans;
    }
};