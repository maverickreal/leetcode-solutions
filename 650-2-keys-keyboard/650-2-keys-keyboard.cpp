class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    vi(vi(ll))dp;
    ll func(ll cur, ll copy) {
        if (cur > n) {
            return LLONG_MAX;
        }
        if (cur == n) {
            return 0;
        }
        if (dp[cur][copy] == -1) {
            dp[cur][copy] = LLONG_MAX;
            if (copy < cur) {
                dp[cur][copy] = min(dp[cur][copy], func(cur, cur));
            }
            dp[cur][copy] = min(dp[cur][copy], func(cur + copy, copy));
            if (dp[cur][copy] < LLONG_MAX) {
                ++dp[cur][copy];
            }
        }
        return dp[cur][copy];
    }
    int minSteps(int N) {
        n = N;
        if (n == 1) {
            return 0;
        }
        dp.resize(n, vi(ll)(n, -1));
        return 1 + func(1, 1);
    }
};