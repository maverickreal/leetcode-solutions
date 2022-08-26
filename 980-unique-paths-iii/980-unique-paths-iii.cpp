class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(vi(bool))vis;
    ll m, n, tar;
    ll func(const vi(vi(int))& v, ll i, ll j, ll cnt) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || v[i][j] == -1) {
            return 0;
        }
        if (v[i][j] == 2) {
            return (cnt == tar);
        }
        vis[i][j] = true;
        ll ans = func(v, i + 1, j, cnt + 1) + func(v, i - 1, j, cnt + 1) + func(v, i, j + 1, cnt + 1) + func(v, i, j - 1, cnt + 1);
        vis[i][j] = false;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        vis.resize(m, vi(bool)(n, false));
        ll res = 0, starti = 0, startj = 0;
        tar = 0;
        for (ll i = 0;i < m;++i) {
            for (ll j = 0;j < n;++j) {
                if (v[i][j] != -1) {
                    ++tar;
                }
                if (v[i][j] == 1) {
                    starti = i, startj = j;
                }
            }
        }
        return func(v, starti, startj, 1);
    }
};