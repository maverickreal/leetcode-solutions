class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(pi))v;
    vi(vi(ll))dp;
    void func(const vi(vi(char))& mat, vi(vi(pi))& v, ll i, ll j) {
        if (j == n) {
            i++;
            j = 0;
        }
        if (i == m) {
            return;
        }
        if (mat[i][j] == '1') {
            dp[i][j] = 1;
            v[i][j] = { 1,1 };
            if (i) {
                v[i][j].second += v[i - 1][j].second;
            }
            if (j) {
                v[i][j].first += v[i][j - 1].first;
            }
            if (i && j) {
                dp[i][j] += min(min(dp[i - 1][j - 1], v[i][j - 1].first), min(dp[i - 1][j - 1], v[i - 1][j].second));
            }
        }
        //cout<<i<<' '<<j<<' '<<v[i][j].first<<' '<<v[i][j].second<<' '<<res<<nl;
        func(mat, v, i, j + 1);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        v.resize(m, vi(pi)(n));
        dp.resize(m, vi(ll)(n));
        func(matrix, v, 0, 0);
        ll ans = 0;
        for (ll i = 0; i < m; i++) {
            for (ll j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return (ans * ans);
    }
};