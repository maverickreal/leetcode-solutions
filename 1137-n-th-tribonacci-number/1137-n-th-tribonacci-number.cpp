class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)dp;
    int tribonacci(int n) {
        if(dp.empty())
            dp.resize(38);
        if (!n)
            return 0;
        if (n < 3)
            return 1;
        if (!dp[n])
            dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};