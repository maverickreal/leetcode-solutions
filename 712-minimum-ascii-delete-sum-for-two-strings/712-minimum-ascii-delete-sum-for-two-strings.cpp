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
    ll func(const string& a, const string& b, ll i, ll j) {
        if (i >= m) {
            ll ans = 0;
            for (;j < n;++j) {
                ans += 97 + b[j] - 'a';
            }
            return ans;
        }
        if (j >= n) {
            ll ans = 0;
            for (;i < m;++i) {
                ans += 97 + a[i] - 'a';
            }
            return ans;
        }
        if (dp[i][j] == -1) {
            ll& ans = dp[i][j];
            ans = 97 + a[i] - 'a' + func(a, b, i + 1, j);
            ans = min(ans, 97 + b[j] - 'a' + func(a, b, i, j + 1));
            if (a[i] == b[j]) {
                ans = min(ans, func(a, b, i + 1, j + 1));
            }
        }
        return dp[i][j];
    }
    int minimumDeleteSum(string& a, string& b) {
        m = a.length(), n = b.length();
        dp.resize(m, vi(ll)(n, -1));
        return func(a, b, 0, 0);
    }
};