class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, tot;
    vi(vi(ll))dp;
    bool func(const vi(int)& v, ll in, ll sum) {
        if ((sum << 1) == tot) {
            return true;
        }
        if ((sum << 1) > tot) {
            return false;
        }
        if (in == sz) {
            return false;
        }
        if (dp[in][sum] == -1) {
            dp[in][sum] = func(v, in + 1, sum) || func(v, in + 1, sum + v[in]);
        }
        return dp[in][sum];
    }
    bool canPartition(vector<int>& v) {
        sz = v.size(), tot = accumulate(v.begin(), v.end(), 0LL);
        if (tot & 1) {
            return false;
        }
        dp.resize(sz, vi(ll)((tot >> 1) + 1, -1));
        return func(v, 0, 0);
    }
};
