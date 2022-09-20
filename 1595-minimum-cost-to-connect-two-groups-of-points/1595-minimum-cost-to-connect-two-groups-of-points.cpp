class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(ll)cols;
    vi(vi(ll))dp;
    ll func(const vi(vi(int))& v, ll in, ll bm) {
        if (in == m) {
            ll ans = 0;
            for (ll c = 0;c < n;++c) {
                if (!((bm >> c) & 1)) {
                    ans += cols[c];
                }
            }
            return ans;
        }
        ll& ans = dp[in][bm];
        if (ans == -1) {
            ans = LLONG_MAX;
            for (ll c = 0;c < n;++c) {
                ans = min(ans, v[in][c] + func(v, in + 1, bm | (1 << c)));
            }
        }
        return ans;
    }
    int connectTwoGroups(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        dp.assign(m, vi(ll)(1 << n, -1));
        cols.assign(n, LLONG_MAX);
        for (ll j = 0;j < n;++j) {
            for (ll i = 0;i < m;++i) {
                cols[j] = min(cols[j], ll(v[i][j]));
            }
        }
        return func(v, 0, 0);
    }
};