class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(ll)dp;
    ll func(const string& s, ll in) {
        if (in >= sz)
            return 1;
        if (s[in] == '0')
            return 0;
        if (dp[in] == -1) {
            dp[in] = func(s, in + 1);
            if (in + 1 < sz) {
                ll n = stoll(s.substr(in, 2));
                if (n > 0 && n < 27)
                    dp[in] += func(s, in + 2);
            }
        }
        return dp[in];
    }
    int numDecodings(string& s) {
        sz = s.length();
        dp.resize(sz, -1);
        return func(s, 0);
    }
};