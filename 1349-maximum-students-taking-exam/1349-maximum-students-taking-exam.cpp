class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(vi(vi(ll))))dp;
    ll func(vi(vi(char))& v, ll i, ll j, ll bmu, ll bml) {
        if (j == n) {
            ++i, j = bmu = bml = 0;
            for (ll k = 0;k < n;++k) {
                if (v[i - 1][k] == '*') {
                    bmu |= 1 << k;
                }
            }
        }
        if (i == m) {
            return 0;
        }
        if (dp[i][j][bmu][bml] == -1) {
            dp[i][j][bmu][bml] = func(v, i, j + 1, bmu, bml);
            if (v[i][j] == '.' && (j == 0 || v[i][j - 1] != '*') && (j == n - 1 || v[i][j + 1] != '*') && (i == 0 || j == 0 || v[i - 1][j - 1] != '*') && (i == 0 || j == n - 1 || v[i - 1][j + 1] != '*')) {
                v[i][j] = '*';
                dp[i][j][bmu][bml] = max(dp[i][j][bmu][bml], 1 + func(v, i, j + 1, bmu, bml | (1 << j)));
                v[i][j] = '.';
            }
        }
        return dp[i][j][bmu][bml];
    }
    int maxStudents(vector<vector<char>>& v) {
        m = v.size(), n = v[0].size();
        dp.assign(m, vi(vi(vi(ll)))(n, vi(vi(ll))(1 << n, vi(ll)(1 << n, -1))));
        return func(v, 0, 0, 0, 0);
    }
};