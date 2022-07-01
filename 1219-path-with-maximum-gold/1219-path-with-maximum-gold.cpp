class Solution {
public:
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define endl '\n'
const ll mod = 1e9;

ll m, n, res = 0;

void func(vi(vi(ll))& v, ll i, ll j, ll tot = 0) {
    res = max(res, tot);
    if (i < 0 || j < 0 || i >= m || j >= n || v[i][j] < 1) return;
    tot += v[i][j];
    ll tmp = v[i][j];
    v[i][j] = 0;
    func(v, i - 1, j, tot);
    func(v, i + 1, j, tot);
    func(v, i, j - 1, tot);
    func(v, i, j + 1, tot);
    v[i][j] = tmp;
}

int getMaximumGold(vector<vector<int>>& v) {
    m = v.size(), n = v[0].size();
    for (ll i = 0;i < m;++i) {
        for (ll j = 0;j < n;++j)
            func(v, i, j);
    }
    return res;
}
};