class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(ll))dp;
    ll func(const vi(vi(int))& v, ll i, ll j) {
        if (dp[i][j] == -1) {
            dp[i][j] = 0;
            if (i > 0 && v[i - 1][j] > v[i][j]) {
                dp[i][j] = max(dp[i][j], func(v, i - 1, j));
            }
            if (i<m - 1 && v[i + 1][j]>v[i][j]) {
                dp[i][j] = max(dp[i][j], func(v, i + 1, j));
            }
            if (j > 0 && v[i][j - 1] > v[i][j]) {
                dp[i][j] = max(dp[i][j], func(v, i, j - 1));
            }
            if (j<n - 1 && v[i][j + 1]>v[i][j]) {
                dp[i][j] = max(dp[i][j], func(v, i, j + 1));
            }
            ++dp[i][j];
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        ll ans = 0;
        dp.resize(m, vi(ll)(n, -1));
        for (ll i = 0;i < m;++i) {
            for (ll j = 0;j < n;++j) {
                ans = max(ans, func(v, i, j));
            }
        }
        return ans;
    }
};