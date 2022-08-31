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
    ll func(const string& s, const string& t, ll i, ll j) {
        if (j == n) {
            return 1;
        }
        if (i == m) {
            return 0;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = func(s, t, i + 1, j);
            if (s[i] == t[j]) {
                dp[i][j] += func(s, t, i + 1, j + 1);
            }
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        dp.resize(m, vi(ll)(n, -1));
        return func(s, t, 0, 0);
    }
};