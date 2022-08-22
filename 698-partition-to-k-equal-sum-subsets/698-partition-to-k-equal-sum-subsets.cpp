class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll sz, bm, tot;
    bool func(const vi(int)& v, const ll& k, ll cur, ll curSum) {
        if (cur == k) {
            return true;
        }
        if (curSum == tot / k) {
            return func(v, k, cur + 1, 0);
        }
        if (dp[cur][bm] == -1) {
            dp[cur][bm] = 0;
            for (ll i = 0;i < sz && ((v[i] + curSum) <= (tot / k));++i) {
                if (bm & (1 << i)) {
                    continue;
                }
                bm |= (1 << i);
                if (func(v, k, cur, curSum + v[i])) {
                    dp[cur][bm] = 1;
                    break;
                }
                bm ^= (1 << i);
            }
        }
        return dp[cur][bm];
    }
    bool canPartitionKSubsets(vector<int>& v, int k) {
        sz = v.size(), bm = 0, tot = accumulate(v.begin(), v.end(), 0);
        if (tot % k) {
            return false;
        }
        sort(v.begin(), v.end());
        dp.resize(k, vi(ll)(1 << 16, -1));
        return func(v, k, 0, 0);
    }
};