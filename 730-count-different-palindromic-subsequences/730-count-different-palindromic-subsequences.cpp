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
        if (dp[i][j] == 0) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 * func(s, i + 1, j - 1);
                ll start = i + 1, end = j - 1;
                while (start < j && s[start] != s[i]) {
                    ++start;
                }
                while (end > start && s[end] != s[j]) {
                    --end;
                }
                if (start < end) {
                    dp[i][j] -= func(s, start + 1, end - 1);
                }
                else if (start > end) {
                    dp[i][j] += 2;
                }
                else {
                    ++dp[i][j];
                }
            }
            else {
                dp[i][j] = func(s, i, j - 1) + func(s, i + 1, j) - func(s, i + 1, j - 1);
            }
        }
        if (dp[i][j] < 0) {
            dp[i][j] += mod;
        }
        else {
            dp[i][j] %= mod;
        }
        return dp[i][j];
    }
    int countPalindromicSubsequences(const string& s) {
        sz = s.length();
        dp.resize(sz, vi(ll)(sz, 0));
        return func(s, 0, sz - 1);
    }
};