class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    ll mod = 1e9 + 7;
    char nl = '\n';
public:
    ll sz;
    vi(ll)dp;
    bool func(vi(ll)& v, ll in) {
        if (in > sz - 2)
            return true;
        if (dp[in] == -1) {
            dp[in] = 0;
            for (ll nxt = 1;nxt <= v[in];++nxt) {
                if (func(v, in + nxt)) {
                    dp[in] = 1;
                    break;
                }
            }
        }
        return dp[in];
    }
    bool canJump(vector<int>& v) {
        sz = v.size();
        dp.resize(sz, -1);
        func(v, 0);
        return dp[0];
    }
};