class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int minimumTotal(vector<vector<int>>& v) {
        ll m = v.size();
        for (ll i = m - 2;i > -1;--i) {
            ll n = v[i].size();
            for (ll j = 0;j < n;++j) {
                v[i][j] += min(v[i + 1][j], v[i + 1][j + 1]);
            }
        }
        return *min_element(v[0].begin(), v[0].end());
    }
};