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
    ll func(vi(ll)& v, ll in) {
        if (dp[in] == -2) {
            for (ll nxt = 1;nxt <= v[in] && (in + nxt < sz);++nxt) {
                ll val = func(v, in + nxt);
                if (val > -1) {
                    if (dp[in] == -2)
                        dp[in] = val + 1;
                    else
                        dp[in] = min(dp[in], val + 1);
                }
            }
            if (dp[in] == -2)
                dp[in] = -1;
        }
        return dp[in];
    }

    ll jump(vector<int>& v) {
        sz = v.size();
        dp.resize(sz, -2);
        dp[sz - 1] = 0;
        func(v, 0);
        return dp[0];
    }
};