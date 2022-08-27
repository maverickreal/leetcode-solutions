class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, tot, tar;
    vi(vi(ll))dp;
    ll func(const vi(int)& v, ll in, ll sum) {
        if (in == sz) {
            return  (((2 * sum) - tot) == tar);
        }
        if (dp[in][sum] == -1) {
            dp[in][sum] = func(v, in + 1, sum) + func(v, in + 1, sum + v[in]);
        }
        return dp[in][sum];
    }
    int findTargetSumWays(vector<int>& v, int target) {
        sz = v.size(), tar = target, tot = accumulate(v.begin(), v.end(), 0LL);
        dp.resize(sz, vi(ll)(tot + 1, -1));
        return func(v, 0, 0);
    }
};