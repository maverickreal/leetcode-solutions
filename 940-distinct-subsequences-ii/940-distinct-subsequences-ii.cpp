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
    ll func(const string& s, ll in, char ch) {
        if (in == sz) {
            return 0;
        }
        if (dp[in][ch - 'a'] == -1) {
            if (s[in] != ch) {
                dp[in][ch-'a'] = func(s, in + 1, ch);
            }
            else {
                dp[in][ch-'a']=1;
                for (char nxt = 'a';nxt <= 'z';++nxt) {
                    dp[in][ch - 'a'] = (dp[in][ch - 'a'] + func(s, in + 1, nxt)) % mod;
                }
            }
        }
        return dp[in][ch - 'a'];
    }
    int distinctSubseqII(string s) {
        sz = s.size();
        ll ans = 0;
        dp.resize(sz, vi(ll)(26, -1));
        for (char ch = 'a';ch <= 'z';++ch) {
            ans = (ans + func(s, 0, ch)) % mod;
        }
        return ans;
    }
};