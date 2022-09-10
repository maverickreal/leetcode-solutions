class Solution {
    typedef long long ll;
    typedef pair<ll, char> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(vi(ll)))dp;
    ll func(const vi(vi(int))& v, ll r, ll b, ll y) {
        if (r == m || b == -1 || y == -1 || b == n || y == n) {
            return 0;
        }
        ll& ans = dp[r][b][y];
        if (ans == -1) {
            ans = v[r][b];
            if (b != y) {
                ans += v[r][y];
            }
            ans += max({ func(v, r + 1, b - 1, y - 1),func(v, r + 1, b - 1, y),func(v, r + 1, b - 1,y + 1),func(v, r + 1, b, y - 1),func(v, r + 1, b, y),func(v, r + 1, b, y + 1), func(v, r + 1, b + 1, y - 1),func(v, r + 1, b + 1,y),func(v, r + 1, b + 1, y + 1) });
        }
        return ans;
    }
    int cherryPickup(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        dp.assign(m, vi(vi(ll))(n, vi(ll)(n, -1)));
        return func(v, 0, 0, n - 1);
    }
};