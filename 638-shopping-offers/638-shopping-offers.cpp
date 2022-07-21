class Solution {
    typedef int ll;
#define vi(x) vector<x>
public:
    ll  sz;
    unordered_map<string, ll>dp;
    ll func(const vi(ll)& n, const vi(ll)& p, const vi(vi(ll))& s) {
        string str;
        for (ll it : n) {
            str.append(to_string(it) + ",");
        }
        if (dp.find(str) == dp.end()) {
            ll cost = INT_MAX;
            for (const vi(ll)& off : s) {
                bool feasible = true;
                for (ll in = 0;in < sz;++in) {
                    if (off[in] > n[in]) {
                        feasible = false;
                        break;
                    }
                }
                if (!feasible) {
                    continue;
                }
                auto ncp = n;
                for (ll in = 0;in < sz;++in) {
                    ncp[in] -= off[in];
                }
                cost = min(cost, off.back() + func(ncp, p, s));
            }
            vi(ll)ncp(sz);
            ll altCost = 0;
            for (ll in = 0;in < sz;++in) {
                altCost += n[in] * p[in];
            }
            cost = min(cost, altCost + func(ncp, p, s));
            dp[str] = cost;
        }
        return dp[str];
    }
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& n) {
        sz = p.size();
        string tmp;
        for (ll in = 0;in < sz;++in) {
            tmp.append("0,");
        }
        dp[tmp] = 0;
        return func(n, p, s);
    }
};