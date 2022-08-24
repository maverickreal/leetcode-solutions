class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    unordered_map<ll,ll>dp;
    ll integerReplacement(ll n) {
        if (n < 3) {
            return n - 1;
        }
        if (dp[n] == 0) {
            ++dp[n];
            if ((n & 1) == 0) {
                dp[n] += integerReplacement(n >> 1);
            }
            else {
                dp[n] += min(integerReplacement(n - 1), integerReplacement(n + 1));
            }
        }
        return dp[n];
    }
};