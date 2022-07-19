class Solution {
public:
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    ll res, m, n;
    void func(const vi(vi(ll))& vs, vi(vi(ll))& vm, ll s, ll cur) {
        if (s == m) {
            res = max(res, cur);
            return;
        }
        for (ll mentor = 0;mentor < m;++mentor) {
            if (vm[mentor][0] != -1) {
                ll sc = 0;
                for (ll i = 0;i < n;++i) {
                    sc += vs[s][i] == vm[mentor][i];
                }
                ll it = vm[mentor][0];
                vm[mentor][0] = -1;
                func(vs, vm, s + 1, cur + sc);
                vm[mentor][0] = it;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& vs, vector<vector<int>>& vm) {
        m = vs.size(), n = vm[0].size();
        res = 0;
        func(vs, vm, 0, 0);
        return res;
    }
};