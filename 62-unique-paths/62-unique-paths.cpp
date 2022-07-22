class Solution {
    typedef long long ll;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(ll))dp;
    ll func(ll i, ll j) {
        if (i < 0 || j < 0 || i >= m || j >= n || dp[i][j] == -1) return 0;
        if (!dp[i][j]) {
            dp[i][j] = -1;
            dp[i][j] = func(i + 1, j) + func(i, j + 1);
        }
        return dp[i][j];
    }
    int uniquePaths(int M, int N) {
        m = M, n = N;
        dp.resize(m, vi(ll)(n));
        dp[m - 1][n - 1] = 1;
        return  func(0, 0);
    }
};