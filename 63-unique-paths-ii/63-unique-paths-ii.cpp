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
    ll func(ll i, ll j, const vi(vi(ll))& v) {
        if (i < 0 || j < 0 || i >= m || j >= n || dp[i][j] == -1 || v[i][j]) return 0;
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (!dp[i][j]) {
            dp[i][j] = -1;
            dp[i][j] = func(i + 1, j, v) + func(i, j + 1, v);
        }
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vi(vi(ll))& v) {
        m = v.size(), n = v[0].size();
        dp.resize(m, vi(ll)(n));
        return  func(0, 0, v);
    }
};