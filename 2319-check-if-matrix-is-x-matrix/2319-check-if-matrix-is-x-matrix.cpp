class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    bool checkXMatrix(vector<vector<int>>& v) {
        ll sz = v.size();
        if (!v[0][0] || !v[0].back() || !v.back()[0] || !v.back().back())
            return false;
        ll r = 0, c = 0;
        for (ll i = 0;i < sz;++i, ++r, ++c) {
            if (!v[r][c])
                return false;
            v[r][c] = -1;
        }
        r = 0, c = sz - 1;
        for (ll i = 0;i < sz;++i, ++r, --c) {
            if (!v[r][c])
                return false;
            v[r][c] = -1;
        }
        r = sz - 1, c = 0;
        for (ll i = 0;i < sz;++i, --r, ++c) {
            if (!v[r][c])
                return false;
            v[r][c] = -1;
        }
        r = sz - 1, c = sz - 1;
        for (ll i = 0;i < sz;++i, --r, --c) {
            if (!v[r][c])
                return false;
            v[r][c] = -1;
        }
        for (const auto& it : v) {
            for (ll ti : it) {
                if (ti == -1)
                    continue;
                if (ti)
                    return false;
            }
        }
        return true;
    }
};