class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int shortestPathLength(const vi(vi(int))& v) {
        list<vi(ll)>q;
        ll n = v.size();
        vi(vi(bool))vis(n, vi(bool)(1 << n, false));
        for (ll i = 0;i < n;++i) {
            q.pb({ i, 0, 1 << i });
            vis[i][1 << i] = true;
        }
        ll ans = -1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop_front();
            if (it[2] == (1 << n) - 1) {
                ans = it[1];
                break;
            }
            for (ll child : v[it[0]]) {
                ll bm = it[2] | (1 << child);
                if (!vis[child][bm]) {
                    q.pb({ child, it[1] + 1, bm });
                    vis[child][bm] = true;
                }
            }
        }
        return ans;
    }
};