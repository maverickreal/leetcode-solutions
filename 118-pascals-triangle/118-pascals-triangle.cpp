class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<vector<int>> generate(int n) {
        vi(vi(ll))res = { {1} };
        if (n == 1)
            return res;
        res.pb({ 1,1 });
        if (n == 2)
            return res;
        for (ll i = 3;i <= n;++i) {
            vi(ll)cur = { 1 };
            for (ll j = 1;j < res.back().size();++j) {
                cur.pb(res.back()[j] + res.back()[j - 1]);
            }
            cur.pb(1);
            res.pb(cur);
        }
        return res;
    }
};