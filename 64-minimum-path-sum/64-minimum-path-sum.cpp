class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(ll))dp;
    ll func(const vi(vi(ll))& v, ll i, ll j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return v[i][j];
        if (dp[i][j] == -1) {
            dp[i][j] = v[i][j] + min(func(v, i + 1, j), func(v, i, j + 1));
        }
        return dp[i][j];

    }
    int minPathSum(const vi(vi(ll))& v) {
        m = v.size(), n = v[0].size();
        dp.resize(m, vi(ll)(n, -1));
        return func(v, 0, 0);
    }
};