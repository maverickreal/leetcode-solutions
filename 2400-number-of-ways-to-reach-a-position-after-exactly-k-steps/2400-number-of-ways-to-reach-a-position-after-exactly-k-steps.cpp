class Solution {
    typedef long long ll;
    const ll mod=1e9 + 7;
public:
    vector<vector<ll>>dp;
    ll func(ll in, const ll& e, ll rem) {
        if (rem == 0) {
            return (in == e);
        }
        ll dis = abs(e - in);
        if (dis > rem) {
            return 0;
        }
        if (dp[dis][rem] == -1) {
            dp[dis][rem] = (func(in + 1, e, rem - 1) + func(in - 1, e, rem - 1)) % mod;
        }
        return dp[dis][rem];
    }
    int numberOfWays(int s, int e, int k) {
        dp.assign(k + 1, vector<ll>(k + 1, -1));
        return func(s, e, k);
    }
};