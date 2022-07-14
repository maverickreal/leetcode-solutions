class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    ll getNum(vi(ll)& v) {
        ll res = 0, sz = v.size();
        for (ll i = sz - 1;i > -1;--i) {
            res += v[i] * (1 << sz - i - 1);
        }
        return res;
    }
public:
    int matrixScore(vector<vector<int>>& v) {
        ll m = v.size(), n = v[0].size();
        for (vi(ll)& it : v) {
            if (!it[0]) {
                for (ll& ti : it)
                    ti = !ti;
            }
        }
        for (ll c = 0;c < n;++c) {
            ll ones = 0;
            for (ll r = 0;r < m;++r)
                ones += v[r][c];
            ll zeroes = m - ones;
            if (zeroes > ones) {
                for (ll r = 0;r < m;++r)
                    v[r][c] = !v[r][c];
            }
        }
        ll res = 0;
        for (vi(ll)& it : v)
            res += getNum(it);
        return res;
    }
};