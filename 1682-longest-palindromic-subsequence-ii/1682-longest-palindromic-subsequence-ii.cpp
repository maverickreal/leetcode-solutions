class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(vi(vi(ll)))dp;
    ll func(const string& s, ll i, ll j, char pre) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j][pre - 'a'] == -1) {
            if (s[i] == s[j]) {
                if (s[i] != pre) {
                    dp[i][j][pre - 'a'] = func(s, i + 1, j - 1, s[i]) + 2;
                }
                else {
                    dp[i][j][pre - 'a'] = func(s, i + 1, j - 1, pre);
                }
            }
            else {
                dp[i][j][pre - 'a'] = max(func(s, i + 1, j, pre), func(s, i, j - 1, pre));
            }
        }
        return dp[i][j][pre - 'a'];
    }
    int longestPalindromeSubseq(const string& s) {
        sz = s.size();
        dp.resize(sz, vi(vi(ll))(sz, vi(ll)(256, -1)));
        return func(s, 0, sz - 1, char('z' + 1));
    }
};