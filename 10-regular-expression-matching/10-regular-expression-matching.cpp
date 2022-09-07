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
    bool func(const string& s, const string& p, ll i, ll j) {
        if (j == n) {
            return i == m;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = 0;
            if (j + 1 < n && p[j + 1] == '*') {
                dp[i][j] = func(s, p, i, j + 2) || (i < m && (s[i] == p[j] || p[j] == '.') && func(s, p, i + 1, j));
            }
            else {
                dp[i][j] = i < m && (s[i] == p[j] || p[j] == '.') && func(s, p, i + 1, j + 1);
            }
        }
        return dp[i][j];
    }
    bool isMatch(string& s, string& p) {
        m = s.size(), n = p.size();
        dp.resize(m + 1, vi(ll)(n + 1, -1));
        return func(s, p, 0, 0);
    }
};