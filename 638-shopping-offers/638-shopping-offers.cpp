class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll res, sz;
    void func(vi(ll)& n, const vi(ll)& p, const vi(vi(ll))& s, ll cost = 0) {
        bool zero = true;
        for (ll it : n) {
            if (it < 0) {
                return;
            }
            if (it) {
                zero = false;
                break;
            }
        }
        if (zero) {
            res = min(res, cost);
            return;
        }
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
            func(ncp, p, s, cost + off.back());
        }
        vi(ll)ncp(sz);
        for (ll in = 0;in < sz;++in) {
            cost += n[in] * p[in];
        }
        func(ncp, p, s, cost);
    }
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& n) {
        sz = p.size();
        res = INT_MAX;
        func(n, p, s);
        return res;
    }
};