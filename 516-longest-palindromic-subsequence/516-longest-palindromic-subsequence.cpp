class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(vi(ll))dp;
    ll func(const string& s, ll i, ll j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] == -1) {
            ll& ans = dp[i][j];
            ans = 0;
            if (s[i] == s[j]) {
                ans = 2 + func(s, i + 1, j - 1);
            }
            ans = max({ans, func(s, i + 1, j), func(s, i, j - 1)});
        }
        return dp[i][j];
    }
    ll longestPalindromeSubseq(const string& s) {
        sz = s.length();
        dp.resize(sz, vi(ll)(sz, -1));
        return func(s, 0, sz - 1);
    }
};