class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(vi(ll)))dp;
    ll func(ll i, ll j, ll rem) {
        if (rem < 0) {
            return 0;
        }
        if (i < 0 || j < 0 || i == m || j == n) {
            return 1;
        }
        if (dp[i][j][rem] == -1) {
            dp[i][j][rem] = (func(i + 1, j, rem - 1) + func(i - 1, j, rem - 1) + func(i, j + 1, rem - 1) + func(i, j - 1, rem - 1))%mod;
        }
        return dp[i][j][rem];
    }
    int findPaths(int M, int N, int mx, int r, int c) {
        m = M, n = N;
        dp.resize(m, vi(vi(ll))(n, vi(ll)(mx + 1, -1)));
        return func(r, c, mx);
    }
};