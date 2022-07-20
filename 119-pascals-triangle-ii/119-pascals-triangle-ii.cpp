class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> getRow(int n) {
        vi(ll)res = { 1 };
        if (n == 0)
            return res;
        res.pb(1);
        if (n == 1)
            return res;
        for (ll i = 2;i <= n;++i) {
            vi(ll)cur = { 1 };
            for (ll j = 1;j < res.size();++j) {
                cur.pb(res[j] + res[j - 1]);
            }
            cur.pb(1);
            res = cur;
        }
        return res;
    }
};