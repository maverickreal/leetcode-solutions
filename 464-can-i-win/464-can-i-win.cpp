class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)dp;
    bool func(const int& mx, const int& tar, ll bm, ll tot) {
        if (tot >= tar) {
            return false;
        }
        if (dp[bm] == -1) {
            dp[bm] = 0;
            for (ll i = mx - 1;i > -1;--i) {
                if ((bm & (1 << i)) == 0) {
                    if (func(mx, tar, bm | (1 << i), tot + i + 1) == 0) {
                        dp[bm] = 1;
                        break;
                    }
                }
            }
        }
        return dp[bm];
    }
    bool canIWin(int mx, int tar) {
        if (tar == 0) {
            return true;
        }
        if (tar > (mx * (mx + 1) / 2)) {
            return false;
        }
        dp.resize(1 << mx, -1);
        return func(mx, tar, 0, 0);
    }
};