class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    void flip(vi(vi(int))& v, ll i, ll j) {
        v[i][j] = !v[i][j];
        if (i > 0) {
            v[i - 1][j] = !v[i - 1][j];
        }
        if (i < m - 1) {
            v[i + 1][j] = !v[i + 1][j];
        }
        if (j > 0) {
            v[i][j - 1] = !v[i][j - 1];
        }
        if (j < n - 1) {
            v[i][j + 1] = !v[i][j + 1];
        }
    }
    ll m, n;
    ll func(vi(vi(int))& v, ll i, ll j) {
        if (j == n) {
            ++i, j = 0;
        }
        if (i == m) {
            for (auto it : v) {
                for (auto ti : it) {
                    if (ti == 1) {
                        return LLONG_MAX;
                    }
                }
            }
            return 0;
        }
        ll ans1 = func(v, i, j + 1);
        flip(v, i, j);
        ll ans2 = func(v, i, j + 1);
        if (ans2 < LLONG_MAX) {
            ++ans2;
        }
        flip(v, i, j);
        return min(ans1, ans2);
    }
    int minFlips(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        ll ret = func(v, 0, 0);
        if (ret == LLONG_MAX) {
            ret = -1;
        }
        return ret;
    }
};