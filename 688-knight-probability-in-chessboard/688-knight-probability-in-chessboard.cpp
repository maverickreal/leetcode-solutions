class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(vi(ld))dp;
    ld func(ll r, ll c, ll rem, const int& n) {
        if (r < 0 || c < 0 || r >= n || c >= n) {
            return 0;
        }
        if (rem == 0) {
            return 1;
        }
        ld& res = dp[(r * n) + c][rem];
        if (res == ld(-1)) {
            --rem;
            res = (func(r - 2, c - 1, rem, n) + func(r - 2, c + 1, rem, n) + func(r + 2, c - 1, rem, n) + func(r + 2, c + 1, rem, n) + func(r - 1, c - 2, rem, n) + func(r + 1, c - 2, rem, n) + func(r - 1, c + 2, rem, n) + func(r + 1, c + 2, rem, n)) / ld(8);
            //cout << r << ' ' << c << ' ' << rem << ' ' << res << nl;
        }
        return res;
    }
    ld knightProbability(int n, int k, int row, int col) {
        dp.assign(n * n, vi(ld)(k + 1, ld(-1)));
        return func(row, col, k, n);
    }
};