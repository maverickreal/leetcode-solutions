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
    bool func(const string& s, ll i, ll j) {
        if (i > j) {
            return true;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = (s[i] == s[j]) && func(s, i + 1, j - 1);
        }
        return dp[i][j];
    }
    int countSubstrings(const string& s) {
        sz = s.length();
        dp.resize(sz, vi(ll)(sz, -1));
        ll ans = 0;
        for (ll i = 0;i < sz;++i) {
            for (ll j = i;j < sz;++j) {
                ans += func(s, i, j);
            }
        }
        return ans;
    }
};